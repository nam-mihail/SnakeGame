#pragma once
#include "StateManager.hpp"
#include "MenuUI.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class MenuState : public State 
{
private:
	MenuUI menu;

public:
	MenuState(Game* game, StateManager* states);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};