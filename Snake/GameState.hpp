#pragma once
#include "Game.hpp"
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"
#include "Map.hpp"
#include "Grid.hpp"
#include "ScoreManager.hpp"

class GameState : public State 
{
private:
    
    Snake snake;
    Grid grid;
    Map map;
	Apple apple;
	ScoreManager scoreManager;

private:
    float baseTickTime = 0.3f;
    float tickTime;
    float tickTimer = 0.0f;
    int point = 1;
    
public:
    GameState(Game* game, StateManager* states);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
	void snakeMove();
    void snakeSetup();
	void spawnApple();
    sf::Vector2i getRandomFreeCell();
};