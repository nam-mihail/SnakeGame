#pragma once
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include "MenuUI.hpp"
#include "Game.hpp"

class DifficultyState : public State
{
private:
	MenuUI menu;
	std::vector<std::string> names;

public:
	DifficultyState(Game* game, StateManager* states);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
	void updateDifficulty(int num);
};