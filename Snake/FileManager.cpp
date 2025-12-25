#include "FileManager.hpp"
#include <fstream>
#include <sstream>
#include "Utils.hpp"

std::unordered_map<std::string, std::string> FileManager::loadKeyValue(const std::string& filename)
{
    std::unordered_map<std::string, std::string> result;
    std::ifstream file(filename);

    if (!file.is_open())
        return result;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        auto pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string val = line.substr(pos + 1);

        result[key] = val;
    }

    return result;
}

void FileManager::saveKeyValue(const std::string& filename, const std::unordered_map<std::string, std::string>& data)
{
    std::ofstream file(filename);

    for (auto& val : data) {
        file << val.first << "=" << val.second << "\n";
    }
}

std::vector<std::pair<sf::String, int>> FileManager::loadScores(const std::string& filename)
{
    std::vector<std::pair<sf::String, int>> scores;
    std::ifstream file(filename, std::ios::binary);

    if (!file) return scores;

    std::string nameUtf8;
    int score;

    while (file >> nameUtf8 >> score)
    {
        sf::String name =
            sf::String::fromUtf8(nameUtf8.begin(), nameUtf8.end());

        scores.emplace_back(name, score);
    }

    return scores;
}

void FileManager::saveScores(const std::string& filename, const std::vector<std::pair<sf::String, int>>& scores)
{
    std::ofstream file(filename);

    for (auto& val : scores) {
		std::string utf8 = Utils::toUtf8String(val.first);
        file << utf8 << " " << val.second << "\n";
    }
}
