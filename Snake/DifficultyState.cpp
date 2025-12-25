#include "DifficultyState.hpp"
#include "Constants.hpp"

DifficultyState::DifficultyState(Game* game, StateManager* states)
	: State(game, states), menu(game->mainFont)
{
	menu.setTitle(u8"Уровень сложности");
	names = { u8"Простой", u8"Тяжелее простого", u8"Средний", u8"Легче тяжелого", u8"Тяжелый" };
	menu.setItems(names , "mid");
	updateDifficulty(static_cast<int>(game->settings.difficulty));
}

void DifficultyState::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::W) {
			game->audio.playSound("click");
			menu.moveUp();
			menu.updateColors();
		}
		else if (event.key.code == sf::Keyboard::S) {
			game->audio.playSound("click");
			menu.moveDown();
			menu.updateColors();
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			game->settings.difficulty = static_cast<Difficulty>(menu.getSelected());
			updateDifficulty(menu.getSelected());
		}
		else if (event.key.code == sf::Keyboard::B) {
			states->popState();
		}
	}
}

void DifficultyState::update(float dt)
{
}

void DifficultyState::draw(sf::RenderWindow& window)
{
	menu.draw(window);
}

void DifficultyState::updateDifficulty(int num) {
	std::vector<std::string> displayNames = names;
	displayNames[num] = u8"> " + displayNames[num] + u8" <";
	menu.setItems(displayNames, "mid");
}
