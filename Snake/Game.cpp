#include "Game.hpp"
#include "Constants.hpp"
#include "MenuState.hpp"
#include <cassert>

Game::Game(int width, int height)
    : window(sf::VideoMode(width, height), "Snake Game") 
{
	assert(mainFont.loadFromFile("assets/fonts/arial.ttf"));
    states.pushState(std::make_unique<MenuState>(this, &states));
    settings.load(fileManager);  
    audio.loadSound("click", "assets/sounds/menu_hover.wav");
    audio.loadSound("eat", "assets/sounds/eat.wav");
    audio.loadSound("gameover", "assets/sounds/gameover.wav");
    audio.loadSound("collision", "assets/sounds/snake_collision.wav");
    audio.loadMusic("assets/musics/background_music.wav");

    audio.setSoundEnabled(settings.sound);
    audio.setMusicEnabled(settings.music);

    audio.playMusic();
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            states.getCurrentState()->handleEvent(event);
            if (states.empty()) {
                window.close();
                return;
            }
        }

        float dt = clock.restart().asSeconds();
        states.getCurrentState()->update(dt);

        window.clear();
        states.getCurrentState()->draw(window);
        window.display();
    }
}
