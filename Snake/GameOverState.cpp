#include "GameOverState.hpp"
#include "Constants.hpp"
#include "GameState.hpp"
#include "Game.hpp"
#include "Utils.hpp"

GameOverState::GameOverState(Game* game, StateManager* states, int score)
	:State(game, states), menu(game->mainFont), finalScore(score), recordsManager(game->mainFont)
{
	records = recordsManager.getRecords();
	if (records.empty() || finalScore > records.back().second || records.size() < 10) {
		isNewRecord = true;
	}
	playerName = u8"XYZ";
	playerText.setFont(game->mainFont);
	playerText.setCharacterSize(24);
	playerText.setFillColor(sf::Color::White);
	playerText.setString(playerName);
	sf::FloatRect bounds = playerText.getLocalBounds();
	playerText.setOrigin(bounds.left + bounds.width / 2.f,
		bounds.top + bounds.height / 2.f);
	playerText.setPosition(Consts::WindowWidth / 2.f, Consts::WindowHeight / 2.f);
	updateMenu();
	game->audio.playSound("gameover");
}

void GameOverState::handleEvent(sf::Event& event)
{
	if (isNewRecord) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				menu.moveUp();
				menu.updateColors();
			}
			else if (event.key.code == sf::Keyboard::S) {
				menu.moveDown();
				menu.updateColors();
			}
			if (event.key.code == sf::Keyboard::Enter) {
				int selected = menu.getSelected();
				if (selected == 0) {
					isAnswerYes = false;
					isNewRecord = false;
					updateMenu();
				}
				else if (selected == 1) {
					isAnswerYes = true;
					isNewRecord = false;
					updateMenu();
				}
			}
		}
	}
	else if (isAnswerYes) {
		if (event.type == sf::Event::TextEntered)
		{
			sf::Uint32 u = event.text.unicode;

			if (u == ' ')
				return;

			if (u >= 32 && u != 127) {
				if (playerName.getSize() < 16) {
					playerName += u;
					playerText.setString(playerName);
					centerText();
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::BackSpace) {
				if (!playerName.isEmpty()) {
					playerName.erase(playerName.getSize() - 1, 1);
					playerText.setString(playerName);
					centerText();
				}
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				addNewRecord();
				isAnswerYes = false;
			}
		}
	}
	else {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::B) {
				states->popState();
			}
			if (event.key.code == sf::Keyboard::W) {
				game->audio.playSound("click");
				menu.moveUp();
				menu.updateColors();
			}
			else if (event.key.code == sf::Keyboard::S) {
				game->audio.playSound("click");
				menu.moveDown();
				menu.updateColors();
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				int selected = menu.getSelected();
				if (selected == 0) {
					states->replaceState(std::make_unique<GameState>(game, states));
				}
				else if (selected == 1) {
					states->popState(2);
				}
			}
		}
	}
	

}

void GameOverState::update(float dt)
{
}

void GameOverState::draw(sf::RenderWindow& window)
{
	if (isNewRecord) {
		menu.draw(window);
	}
	else if (isAnswerYes) {
		sf::RectangleShape inputBox;
		inputBox.setSize({ 300.f, 40.f });
		inputBox.setFillColor(sf::Color(30, 30, 30));
		inputBox.setOutlineColor(sf::Color::White);
		inputBox.setOutlineThickness(2.f);
		inputBox.setPosition(Consts::WindowWidth / 2.f, Consts::WindowHeight / 2.f);
		inputBox.setOrigin(inputBox.getSize().x / 2.f, inputBox.getSize().y / 2.f);
		window.draw(inputBox);
		window.draw(playerText);
	}
	else if (!isAnswerYes && !isNewRecord)
	{
		menu.draw(window);
		sf::Text scoreText;
		scoreText.setFont(game->mainFont);
		scoreText.setString(std::to_string(finalScore));
		scoreText.setCharacterSize(50);
		scoreText.setPosition(Consts::WindowWidth / 2.0f - scoreText.getLocalBounds().width / 2.f, menu.getTitle().getPosition().y + 100);
		window.draw(scoreText);
		recordsManager.draw(window, records, 5);
	}
	
	
}

void GameOverState::centerText()
{
	sf::FloatRect bounds = playerText.getLocalBounds();
	playerText.setOrigin(bounds.left + bounds.width / 2.f,
		bounds.top + bounds.height / 2.f);

	playerText.setPosition(Consts::WindowWidth / 2.f, Consts::WindowHeight / 2.f);
}

void GameOverState::addNewRecord()
{
	if (records.size() == 0) {
		records.push_back({ playerName, finalScore });
	}
	else if (records.size() < 10) {
		records.push_back({ playerName, finalScore });
	}
	else {
		records.end()->first = playerName;
		records.end()->second = finalScore;
	}
	recordsManager.saveRecords(records);
}

void GameOverState::updateMenu()
{
	if (isNewRecord) {
		menu.setTitle(u8"Хотите записать рекорд?");
		menu.setItems({ u8"Нет" , u8"Да" }, "mid");
	}
	else {
		menu.setTitle(u8"Количество очков");
		menu.setItems({ u8"Новая игра",u8"Вернуться в меню" }, "bottom");
	}
}