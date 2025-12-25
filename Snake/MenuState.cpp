#include "MenuState.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "SettingState.hpp"
#include "RecordsState.hpp"
#include "DifficultyState.hpp"

MenuState::MenuState(Game* game, StateManager* states)
	:State(game, states), menu(game->mainFont)
{
	menu.setTitle(u8"Змейка");
	menu.setItems({ u8"Начать игру", u8"Уровень сложности", u8"Таблица рекордов", u8"Настройки", u8"Выход" }, "mid");
}

void MenuState::handleEvent(sf::Event& event)
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
			int selected = menu.getSelected();
			if (selected == 0) {
				states->pushState(std::make_unique<GameState>(game, states));
			}
			else if (selected == 1) {
				states->pushState(std::make_unique<DifficultyState>(game, states));
			}
			else if (selected == 2) {
				states->pushState(std::make_unique<RecordsState>(game, states));
			}
			else if (selected == 3) {
				states->pushState(std::make_unique<SettingState>(game, states));
			}
			else if (selected == 4) {
				states->popState();
			}
		}
	}
}
void MenuState::update(float dt)
{

}

void MenuState::draw(sf::RenderWindow& window)
{
	menu.draw(window);
}

