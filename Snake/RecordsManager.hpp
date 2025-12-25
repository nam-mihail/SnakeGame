#pragma once
#include "FileManager.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.hpp"

class RecordsManager {
private:
	FileManager fileManager;
	sf::Font font;
public:
	RecordsManager(sf::Font font);
	void saveRecords(std::vector<std::pair<sf::String, int>> &records);
	std::vector<std::pair<sf::String, int>> getRecords();
	void draw(sf::RenderWindow& window, std::vector<std::pair<sf::String, int>> getRecords, int count);
	std::vector<std::pair<sf::String, int>> sortRecords(std::vector<std::pair<sf::String, int>> &records);
};