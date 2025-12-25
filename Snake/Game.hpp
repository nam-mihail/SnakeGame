#pragma once
#include <SFML/Graphics.hpp>
#include "FileManager.hpp"
#include "SettingsManager.hpp"
#include "StateManager.hpp"
#include "AudioManager.hpp"


class Game {
public: 
	Game(int width, int height);
	void run();
	SettingsManager settings;
	sf::Font mainFont;
	FileManager fileManager;
	AudioManager audio;

private:
	sf::RenderWindow window;
	sf::Clock clock;
	StateManager states;
};