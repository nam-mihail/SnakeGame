#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right };

class Snake {
public:
    Snake();

    void setDirection(Direction dir);
    void draw(sf::RenderWindow& win);
    Direction getDirection();
	std::vector<sf::Vector2i>& getSnakeBody();
    void setCanChangeDirection(bool canChange);
    sf::Vector2i getHead() const;

private:
    std::vector<sf::Vector2i> segments;
    Direction direction = Direction::Right;
    bool canChangeDirection = true;

    sf::Texture headTexture;
    sf::Texture bodyTexture;
    sf::Sprite sprite;
};