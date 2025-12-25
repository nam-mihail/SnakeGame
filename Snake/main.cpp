#include "Game.hpp"
#include "Constants.hpp"

int main()
{
    Game game(Consts::WindowWidth, Consts::WindowHeight);
    game.run();
    return 0;
}