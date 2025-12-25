#include "Map.hpp"
#include "Constants.hpp"

Map::Map() {}

void Map::draw(sf::RenderWindow& win, const Grid& grid) {
	win.clear(sf::Color(75, 115, 46));
	for (int y = 0; y < Consts::GridHeight; ++y) {
		for (int x = 0; x < Consts::GridWidth; ++x) {
			sf::RectangleShape cellShape(sf::Vector2f(Consts::CellSize, Consts::CellSize));
			cellShape.setPosition(x * Consts::CellSize, y * Consts::CellSize + Consts::OffSetY);

			CellType cell = grid.getCell(x, y);

			if (cell == CellType::Wall)
				cellShape.setFillColor(sf::Color(87, 137, 50));
			else if (cell != CellType::Wall && (x + y) % 2 == 0) 
				cellShape.setFillColor(sf::Color(169, 215, 82));
			else 
				cellShape.setFillColor(sf::Color(162, 208, 75));

			win.draw(cellShape);
		}
	}
}