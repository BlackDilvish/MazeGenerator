#include <SFML/Graphics.hpp>
#include"Game.h"

int main()
{
    Game game;

    while(game.IsPlaying())
        game.UpdateGame();

    return 0;
}
