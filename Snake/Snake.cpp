#include "Snake.hpp"
#include "Constants.hpp"
#include "Utils.hpp"
#include <cassert>

Snake::Snake() {
    segments.push_back({ Consts::GridWidth / 2, Consts::GridHeight / 2 });
    segments.push_back({ Consts::GridWidth / 2 - 1, Consts::GridHeight / 2 });
    segments.push_back({ Consts::GridWidth / 2 - 2, Consts::GridHeight / 2 });

    assert(headTexture.loadFromFile("assets/textures/snake_head.png"));
    assert(bodyTexture.loadFromFile("assets/textures/snake_body.png"));

    sprite.setOrigin(Consts::CellSize / 2, Consts::CellSize / 2);
	
}

void Snake::setDirection(Direction dir) {
    if (!canChangeDirection)
        return;

    if ((direction == Direction::Up && dir == Direction::Down) ||
        (direction == Direction::Down && dir == Direction::Up) ||
        (direction == Direction::Left && dir == Direction::Right) ||
        (direction == Direction::Right && dir == Direction::Left))
        return;

    direction = dir;
    canChangeDirection = false;
}

Direction Snake::getDirection() {
    return direction;
}

std::vector<sf::Vector2i>& Snake::getSnakeBody() {
    return segments;
}

void Snake::draw(sf::RenderWindow& win) {
    for (int i = 0; i < segments.size(); i++) {
        sprite.setPosition(Utils::gridToWorld(segments[i]));
        if (i == 0) {
            sprite.setTexture(headTexture);

            if (segments.size() > 1) {
                sf::Vector2i head = segments[0];
                sf::Vector2i neck = segments[1];
                sf::Vector2i dir = head - neck;

                if (dir.x == 1)  sprite.setRotation(90);  
                if (dir.x == -1) sprite.setRotation(270); 
                if (dir.y == 1)  sprite.setRotation(180);  
                if (dir.y == -1) sprite.setRotation(0); 
            }
        }
        else
        {
            sprite.setTexture(bodyTexture);
        }
        win.draw(sprite);
    }
}

void Snake::setCanChangeDirection(bool canChange) {
    canChangeDirection = canChange;
}

sf::Vector2i Snake::getHead() const {
    return segments.front();
}