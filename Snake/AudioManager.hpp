#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class AudioManager {
public:
	void loadSound(const std::string& name, const std::string& filename);
	void playSound(const std::string& name);
	void loadMusic(const std::string& filename);
	void playMusic(bool loop = true);
	void stopMusic();
	void setSoundEnabled(bool enabled);
	void setMusicEnabled(bool enabled);

private:
	std::unordered_map<std::string, sf::SoundBuffer> buffers;
	std::unordered_map<std::string, sf::Sound> sounds;

	sf::Music music;

	bool soundEnabled = true;
	bool musicEnabled = true;

};