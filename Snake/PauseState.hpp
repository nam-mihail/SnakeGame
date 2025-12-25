#pragma once
#include <SFML/Graphics.hpp>
#include "MenuUI.hpp"
#include "StateManager.hpp"


class PauseState : public State
{
private:
	MenuUI menu;

public:
	PauseState(Game* game, StateManager* states);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};