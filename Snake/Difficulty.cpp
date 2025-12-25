#include "Difficulty.hpp"
#include <array>

DifficultySettings getDifficultySettings(Difficulty d)
{
    static const std::array<DifficultySettings, 5> table = { {
        {1.f,  2},
        {2.f,  4},
        {3.f,  6},
        {4.f,  8},
        {5.f, 10}
    } };

    return table[static_cast<int>(d)];
}
