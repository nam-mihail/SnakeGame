#include "SettingState.hpp"
#include "Game.hpp"

SettingState::SettingState(Game* game, StateManager* states)
	: State(game, states), menu(game->mainFont)
{
	menu.setTitle(u8"Настройки");
	menu.setBoolItems({ {u8"Звук", game->settings.sound}, {u8"Музыка", game->settings.music} });
}

void SettingState::handleEvent(sf::Event& event)
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
		else if (event.key.code == sf::Keyboard::B) {
			game->settings.save(game->fileManager);
			states->popState();
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			int selected = menu.getSelected();
			if (selected == 0) {
				game->settings.sound = !game->settings.sound;
				game->audio.setSoundEnabled(game->settings.sound);
				menu.getBoolItems()[selected].second.setChecked(game->settings.sound);
			}
			else if (selected == 1) {
				game->settings.music = !game->settings.music;
				game->audio.setMusicEnabled(game->settings.music);
				game->audio.playMusic("assets/musics/background_music.wav");
				menu.getBoolItems()[selected].second.setChecked(game->settings.music);
			}
		}
	}
}

void SettingState::update(float dt)
{
}

void SettingState::draw(sf::RenderWindow& window)
{
	menu.drawBoolItems(window);
}
