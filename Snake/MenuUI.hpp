#pragma once
#include <SFML/Graphics.hpp>
#include "CheckBox.hpp"

class MenuUI {
private:
    std::vector<sf::Text> items;
	std::vector<std::pair<sf::Text, CheckBox>> boolItems;
    sf::Text title;
    sf::Font& font;
    int selected = 0;

public:
    MenuUI(sf::Font& font);

    void setItems(const std::vector<std::string>& names, std::string pos);
	sf::Text& getItem(int index);
	void setBoolItems(const std::vector<std::pair<std::string, bool>>& names);
	std::vector<std::pair<sf::Text, CheckBox>> &getBoolItems();
    void setTitle(std::string titleText);
    void updateColors();
    void moveUp();
    void moveDown();
    int getSelected() const;
    void draw(sf::RenderWindow& window);
	void drawBoolItems(sf::RenderWindow& window);
    sf::Text &getTitle();
	sf::Text createText(std::string name, int index, float startY);
};