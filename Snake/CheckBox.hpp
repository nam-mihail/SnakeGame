#pragma once
#include <SFML/Graphics.hpp>

class CheckBox {
public:
	CheckBox(float x, float y, bool checked);

	void setChecked(bool checked);
	void draw(sf::RenderWindow& window) const;

private:
	void updateCross();

	sf::VertexArray cross;
	bool checked;
	sf::RectangleShape box;
};