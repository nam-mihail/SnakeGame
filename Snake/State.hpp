#pragma once
#include <SFML/Graphics.hpp>

class StateManager;
class Game;

class State {
public:
    State(Game* game, StateManager* states) : game(game), states(states) {}
    virtual ~State() = default;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:      
	Game* game;
    StateManager* states;
};