#include "ScoreManager.hpp"
#include <cassert>

ScoreManager::ScoreManager() {
	assert(font.loadFromFile("assets/fonts/arial.ttf"));
		
	
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(10.f, 20.f);
	text.setString("Score: 0");
}

void ScoreManager::addScore(int amount) {
	score += amount;
	text.setString("Score: " + std::to_string(score));
}

int ScoreManager::getScore() const {
	return score;
}

void ScoreManager::draw(sf::RenderWindow& window) {
	window.draw(text);
}