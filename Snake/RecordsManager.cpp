#include "RecordsManager.hpp"
#include "Utils.hpp"

RecordsManager::RecordsManager(sf::Font font):
	font(font)
{}

void RecordsManager::saveRecords(std::vector<std::pair<sf::String, int>> &records)
{
	fileManager.saveScores("assets/records.cfg", records);
	sortRecords(records);
	return;
}

std::vector<std::pair<sf::String, int>> RecordsManager::getRecords()
{
	std::vector<std::pair<sf::String, int>> records = fileManager.loadScores("assets/records.cfg");
	if (records.empty()) {
		return records;
	}
	sortRecords(records);
	return records;
}

void RecordsManager::draw(sf::RenderWindow& window, std::vector<std::pair<sf::String, int>> records, int count)
{
	const float centerX = Consts::WindowWidth / 2.0f;
	const float centerY = Consts::WindowHeight / 2.0f;

	const float spacing = 45.0f;

	if (count > records.size()) {
		count = records.size();
	}

	float startY = centerY - (count * spacing - 100) / 2.0f;

	for (int i = 0; i < count; i++) {
		sf::String str = records[i].first;
		sf::Text text;
		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(26);
		text.setOrigin(0, text.getLocalBounds().height / 2.f);
		text.setPosition(centerX - 150, startY + i * spacing);

		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setString(std::to_string(records[i].second));
		scoreText.setCharacterSize(26);
		scoreText.setOrigin(scoreText.getLocalBounds().width, scoreText.getLocalBounds().height / 2.f);
		scoreText.setPosition(centerX + 150, startY + i * spacing);

		window.draw(text);
		window.draw(scoreText);
	}
}

std::vector<std::pair<sf::String, int>> RecordsManager::sortRecords(std::vector<std::pair<sf::String, int>> &records)
{
	std::sort(records.begin(), records.end(),
		[](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
			return b.second < a.second;
		});
	if (10 < records.size()) {
		records.resize(10);
	}
	return records;
}

