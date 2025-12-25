#include "Grid.hpp"
#include "Constants.hpp"

Grid::Grid(int w, int h)
    : width(w), height(h)
{
    grid.resize(height, std::vector<CellType>(width, CellType::Empty));

    for (int x = 0; x < width; x++) {
        grid[0][x] = CellType::Wall;
        grid[height - 1][x] = CellType::Wall;
    }

    for (int y = 0; y < height; y++) {
        grid[y][0] = CellType::Wall;
        grid[y][width - 1] = CellType::Wall;
    }
}

void Grid::setCell(sf::Vector2i cell, CellType type) {
    grid[cell.y][cell.x] = type;
}

CellType Grid::getCell(int x, int y) const {
    return grid[y][x];
}

void Grid::clearCell(int x, int y) {
    grid[y][x] = CellType::Empty;
}

std::vector<std::pair<int, int>> Grid::getEmptyCells() const {
    std::vector<std::pair<int, int>> emptyCells;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == CellType::Empty) {
                emptyCells.emplace_back(x, y);
            }
        }
    }
    return emptyCells;
}
