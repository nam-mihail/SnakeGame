#include "CheckBox.hpp"

CheckBox::CheckBox(float x, float y, bool checked)
	:checked(checked),
	cross(sf::Lines, 4)
{
    box.setSize({ 24.f, 24.f });
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2.f);
    box.setPosition(x + 300, y);

    float s = box.getSize().x;

    cross[0].position = { box.getPosition().x, box.getPosition().y };
    cross[1].position = { box.getPosition().x + s, box.getPosition().y + s };
    cross[2].position = { box.getPosition().x + s, box.getPosition().y };
    cross[3].position = { box.getPosition().x, box.getPosition().y + s };

    updateCross();
}

void CheckBox::setChecked(bool checked)
{
    this -> checked = checked;
	updateCross();
}

void CheckBox::updateCross()
{   
    if (checked) {
        for (int i = 0; i < 4; i++)
            cross[i].color = sf::Color::White;
    }
    else {
        for (int i = 0; i < 4; i++)
            cross[i].color = sf::Color::Transparent;
    }
}

void CheckBox::draw(sf::RenderWindow& window) const
{
    window.draw(box);
    if (checked) {
	    window.draw(cross);
    }   
}
