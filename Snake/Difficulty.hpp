#pragma once

enum class Difficulty {
	Easy = 0,
	Normal,
	Hard,
	VeryHard,
	Extreme
};

struct DifficultySettings {
	float snakeSpeed;       
	int pointsPerFood;     
};

DifficultySettings getDifficultySettings(Difficulty d);