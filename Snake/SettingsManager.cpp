#include "SettingsManager.hpp"
#include "FileManager.hpp"

void SettingsManager::load(FileManager& fm)
{
    auto data = fm.loadKeyValue("assets/settings.cfg");

    if (data.find("sound") != data.end())   sound = (data["sound"] == "true");
    if (data.find("music") != data.end())      music = (data["music"] == "true");

}

void SettingsManager::save(FileManager& fm)
{
    std::unordered_map<std::string, std::string> data;

    data["sound"] = sound ? "true" : "false";
    data["music"] = music ? "true" : "false";

    fm.saveKeyValue("assets/settings.cfg", data);
}