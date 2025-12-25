#include "AudioManager.hpp"
#include <cassert>

void AudioManager::loadSound(const std::string& name, const std::string& filename)
{
	sf::SoundBuffer buffer;
	assert(buffer.loadFromFile(filename));
	buffers[name] = buffer;

	sf::Sound sound;
	sound.setBuffer(buffers[name]);
	sounds[name] = sound;
}

void AudioManager::playSound(const std::string& name)
{
	if(soundEnabled) {
		sounds[name].play();
	}
}

void AudioManager::loadMusic(const std::string& filename)
{
	assert(music.openFromFile(filename));
}

void AudioManager::playMusic(bool loop)
{
	if (musicEnabled) {
		music.setLoop(loop);
		music.play();
	}
}

void AudioManager::stopMusic()
{
	music.stop();
}

void AudioManager::setSoundEnabled(bool enabled)
{
	soundEnabled = enabled;
}

void AudioManager::setMusicEnabled(bool enabled)
{
	musicEnabled = enabled;
	music.play();
	if (!musicEnabled) {
		music.stop();
	}
}
