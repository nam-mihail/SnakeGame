#pragma once
#include <SFML/Graphics.hpp>

class Apple {
public:
    Apple();

    void setGridPos(sf::Vector2i pos);
    sf::Vector2i getGridPos() const;
    void draw(sf::RenderWindow& win);
    void loadTexture();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2i gridPos;
    
};