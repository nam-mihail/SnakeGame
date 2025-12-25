#pragma once
#include <SFML/Graphics.hpp>

class ScoreManager {
public:
    ScoreManager();

    void addScore(int amount);
    int getScore() const;

    void draw(sf::RenderWindow& window);

private:
    int score = 0;

    sf::Font font;
    sf::Text text;
};