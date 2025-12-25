#include "RecordsState.hpp"
#include "Game.hpp"

RecordsState::RecordsState(Game* game, StateManager* states)
	: State(game, states), menu(game->mainFont), recordsManager(game->mainFont)
{
	menu.setTitle(u8"Таблица рекордов");
	scores = recordsManager.getRecords();
}

void RecordsState::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::B) {
			states->popState();
		}
	}
}

void RecordsState::update(float dt)
{
}

void RecordsState::draw(sf::RenderWindow& window)
{
	menu.draw(window);
	recordsManager.draw(window, scores, 10);
}
