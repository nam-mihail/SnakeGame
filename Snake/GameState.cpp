#include "GameState.hpp"
#include "Constants.hpp"
#include "Utils.hpp"
#include "GameOverState.hpp"
#include "PauseState.hpp"
#include "Difficulty.hpp"
#include <random>

GameState::GameState(Game* game, StateManager* states):
    map(),
    grid(Consts::GridWidth, Consts::GridHeight),
    snake(),
    apple(),
	scoreManager(),
	State(game, states)
{
    snakeSetup();
	spawnApple();
	auto settings = getDifficultySettings(game->settings.difficulty);
	tickTime = baseTickTime / settings.snakeSpeed;
	point = settings.pointsPerFood;
}

void GameState::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            states->pushState(std::make_unique<PauseState>(game, states));
		}
        if (event.key.code == sf::Keyboard::B) {
            states->popState();
        }
        if (event.key.code == sf::Keyboard::W)
            snake.setDirection(Direction::Up);
        else if (event.key.code == sf::Keyboard::S)
            snake.setDirection(Direction::Down);
        else if (event.key.code == sf::Keyboard::A)
            snake.setDirection(Direction::Left);
        else if (event.key.code == sf::Keyboard::D)
            snake.setDirection(Direction::Right);
    }
}

void GameState::update(float dt)
{
    tickTimer += dt;

    if (tickTimer >= tickTime)
    {
        snakeMove();
        tickTimer = 0.0f;
    }
}

void GameState::draw(sf::RenderWindow& window)
{
    map.draw(window, grid);
    apple.draw(window);
    snake.draw(window);
    scoreManager.draw(window);
}

void GameState::snakeSetup() {
    std::vector<sf::Vector2i>& body = snake.getSnakeBody();
    for (const auto& segment : body) {
        grid.setCell(segment, CellType::SnakeBody);
    }
}
void GameState::snakeMove() {
    sf::Vector2i oldHead = snake.getHead();
    sf::Vector2i newHead = oldHead;
    std::vector<sf::Vector2i>& body = snake.getSnakeBody();

    switch (snake.getDirection()) {
    case Direction::Up:    newHead.y -= 1; break;
    case Direction::Down:  newHead.y += 1; break;
    case Direction::Left:  newHead.x -= 1; break;
    case Direction::Right: newHead.x += 1; break;
    }

    if (grid.getCell(newHead.x, newHead.y) == CellType::SnakeBody ||
        grid.getCell(newHead.x, newHead.y) == CellType::Wall) {
		game->audio.playSound("collision");	
        states->pushState(std::make_unique<GameOverState>(game, states, scoreManager.getScore()));
    }

    if (grid.getCell(newHead.x, newHead.y) != CellType::Food) {
        grid.clearCell(body.back().x, body.back().y);
        body.pop_back();
    }
    else {
        game->audio.playSound("eat");
        spawnApple();
		scoreManager.addScore(point);
    }

    grid.setCell(oldHead, CellType::SnakeBody);
    body.insert(body.begin(), newHead);
    grid.setCell(newHead, CellType::SnakeHead);
    snake.setCanChangeDirection(true);
}

void GameState::spawnApple() {
    sf::Vector2i freeCell = getRandomFreeCell();
    if (freeCell == sf::Vector2i{ 0,0 })
    {
        return;
    }
    apple.setGridPos(freeCell);
    grid.setCell(freeCell, CellType::Food);
}

sf::Vector2i GameState::getRandomFreeCell() {
    std::vector<sf::Vector2i> free;

    for (int y = 0; y < Consts::GridHeight - 1; ++y) {
        for (int x = 0; x < Consts::GridWidth - 1; ++x) {
            if (grid.getCell(x, y) == CellType::Empty)
                free.push_back({ x, y });
        }
    }

    if (free.empty())
        return { 0,0 };

    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, free.size() - 1);

    return free[dist(rng)];
}