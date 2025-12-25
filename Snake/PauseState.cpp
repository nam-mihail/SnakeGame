#include "PauseState.hpp"
#include "Game.hpp"

PauseState::PauseState(Game* game, StateManager* states)
	: State(game, states), menu(game->mainFont)
{
	menu.setTitle(u8"Пауза");
	menu.setItems({ u8"Возобновить", u8"Выход в меню" }, "mid");
}

void PauseState::handleEvent(sf::Event& event) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		game->audio.playSound("click");
		menu.moveUp();
		menu.updateColors();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		game->audio.playSound("click");
		menu.moveDown();
		menu.updateColors();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		int selected = menu.getSelected();
		if (selected == 0) {
			states->popState();
		}
		else if (selected == 1) {
			states->popState(2);
		}
	}
}

void PauseState::update(float dt)
{
	
}

void PauseState::draw(sf::RenderWindow& window)
{
	menu.draw(window);
}