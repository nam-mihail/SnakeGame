#pragma once
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include "MenuUI.hpp"
#include "RecordsManager.hpp"

class RecordsState : public State
{
private:
	MenuUI menu;
	RecordsManager recordsManager;
	std::vector<std::pair<sf::String, int>> scores;
	
public:
	RecordsState(Game* game, StateManager* states);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};