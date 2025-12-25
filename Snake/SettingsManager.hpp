#pragma once
#include <string>
#include <map>
#include "Difficulty.hpp"

class FileManager;

class SettingsManager {
public:
    bool sound;
    bool music;
	Difficulty difficulty = Difficulty::Easy;

    void load(FileManager& fm);
    void save(FileManager& fm);
};