#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

class Map {
public:
	Map();
	void draw(sf::RenderWindow& win, const Grid& grid);
};