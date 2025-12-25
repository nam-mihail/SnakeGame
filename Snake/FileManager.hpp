#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class FileManager {
public:
    std::unordered_map<std::string, std::string> loadKeyValue(const std::string& filename);

    void saveKeyValue(
        const std::string& filename,
        const std::unordered_map<std::string, std::string>& data
    );

    std::vector<std::pair<sf::String, int>> loadScores(const std::string& filename);

    void saveScores(
        const std::string& filename,
        const std::vector<std::pair<sf::String, int>>& scores
    );
};