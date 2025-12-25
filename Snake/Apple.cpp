#include "Apple.hpp"
#include "Utils.hpp"
#include <cassert>


Apple::Apple()
{
    loadTexture();
}

void Apple::loadTexture() {

    assert(texture.loadFromFile("assets/textures/apple.png"));
    sprite.setTexture(texture);
    float scaleX = Consts::CellSize / texture.getSize().x;
    float scaleY = Consts::CellSize / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}

void Apple::setGridPos(sf::Vector2i pos) {
    gridPos = pos;
    sprite.setPosition(Utils::gridToWorld(pos));
}

sf::Vector2i Apple::getGridPos() const {
    return gridPos;
}

void Apple::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

