#pragma once
#include "StateManager.hpp"
#include <SFMl/Graphics.hpp>
#include "MenuUI.hpp"
#include "RecordsManager.hpp"

class GameOverState : public State
{
private:
	MenuUI menu;
	int finalScore;
	RecordsManager recordsManager;
	sf::String playerName;
	sf::Text playerText;
	bool isNewRecord = false;
	std::vector<std::pair<sf::String, int>> records;
	bool isAnswerYes = false;

public:
	GameOverState(Game* game, StateManager* states, int score);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	void centerText();
	void addNewRecord();
	void updateMenu();
};