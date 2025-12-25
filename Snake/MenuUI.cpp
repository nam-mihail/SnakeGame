#include "MenuUI.hpp"
#include "Constants.hpp"

MenuUI::MenuUI(sf::Font& f) 
    :font(f)
{}

void MenuUI::setTitle(const std::string titleText) {
    if (titleText.empty()) {
        return;
	}
    sf::String str = sf::String::fromUtf8(titleText.begin(), titleText.end());
    title.setFont(font);
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setString(str);
    float x = Consts::WindowWidth / 2.f - title.getLocalBounds().width / 2.f;
    title.setPosition(x, 50.f);
}

sf::Text &MenuUI::getTitle() {
	return title;
}

sf::Text MenuUI::createText(std::string name, int index, float startY)
{
    const float spacing = 60.0f;

    sf::String str = sf::String::fromUtf8(name.begin(), name.end());
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(36);
    sf::FloatRect b = text.getLocalBounds();
    text.setOrigin(b.width / 2, b.height / 2);

    text.setPosition(Consts::CenterX, startY + index * spacing);
    return text;
}

void MenuUI::setItems(const std::vector<std::string>& names, std::string pos) {

    items.clear();

    const float spacing = 60.0f;
	float startY = 0;

    if (pos == "mid") {
        startY = Consts::CenterY - (names.size() * spacing) / 2.0f;
    }
    else if (pos == "bottom") {
        startY = Consts::CenterY - (names.size() * spacing) / 2.0f + 250;
	}
    
    for (int i = 0; i < names.size(); i++) {
        sf::Text text;
		text = createText(names[i], i, startY);
		items.push_back(text);
    }

    updateColors();
}

sf::Text& MenuUI::getItem(int index)
{
	return items[index];
}

void MenuUI::setBoolItems(const std::vector<std::pair<std::string, bool>>& names) {

    const float spacing = 60.0f;

    float startY = Consts::CenterY - (names.size() * spacing) / 2.0f;

    for (int i = 0; i < names.size(); i++) {
        
        sf::Text text;
        text = createText(names[i].first, i, startY);
        text.setOrigin(0, text.getOrigin().y);
        text.setPosition(Consts::CenterX - 150, startY + i * spacing);
        items.push_back(text);

        CheckBox checkBox(text.getPosition().x, text.getPosition().y, names[i].second);

        boolItems.push_back({ text, checkBox});
    }

    updateColors();
}

void MenuUI::updateColors() {
    if (items.size() > 0) {
        for (int i = 0; i < items.size(); i++) {
            items[i].setFillColor(i == selected ? sf::Color::Green : sf::Color::White);
        }
    }
    else {
        for (int i = 0; i < boolItems.size(); i++) {
            boolItems[i].first.setFillColor(i == selected ? sf::Color::Green : sf::Color::White);
        }
    }
}

void MenuUI::moveUp() {
    if (selected > 0) selected--;
    updateColors();
}

void MenuUI::moveDown() {
    if (selected + 1 < items.size() || selected + 1 < boolItems.size()) selected++;
    updateColors();
}

int MenuUI::getSelected() const {
    return selected;
}

void MenuUI::draw(sf::RenderWindow& window) {
	window.draw(title);
	if (items.empty()) return;
    for (auto& i : items)
        window.draw(i);
}

void MenuUI::drawBoolItems(sf::RenderWindow& window)
{
    window.draw(title);
    for (auto& boolItem : boolItems) { 
        window.draw(boolItem.first);
		boolItem.second.draw(window);
    }
}

std::vector<std::pair<sf::Text, CheckBox>> &MenuUI::getBoolItems() 
{
    return boolItems;
}

