#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum class CellType {
    Empty,
    SnakeBody,
    Food,
    Wall,
    SnakeHead
};

class Grid {
public:
    Grid(int width, int height);

    void setCell(sf::Vector2i cell, CellType type);
    CellType getCell(int x, int y) const;
    std::vector<std::pair<int, int>> getEmptyCells() const;
    void clearCell(int x, int y);

private:
    int width;
    int height;
    std::vector<std::vector<CellType>> grid;
};