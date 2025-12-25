#pragma once
#include <SFML/Graphics.hpp>
#include "MenuUI.hpp"
#include "StateManager.hpp"

class SettingState : public State
{
private:
	MenuUI menu;

public:
	SettingState(Game* game, StateManager* states);
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};