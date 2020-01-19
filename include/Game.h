#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<utility>
#include"MazeTile.h"

class Game
{
    public:
        Game();
        ~Game();

        void UpdateGame();
        void RenderGame();
        bool IsPlaying() const;

    private:

        void InitWindow();
        void InitMaze(std::pair<size_t, size_t> dimensions);

        void Pollevents();
        void UpdateMaze();

        void RenderMaze();

        std::vector<MazeTile> _mazeTiles;

        sf::RenderWindow* _window;
};

#endif // GAME_H
