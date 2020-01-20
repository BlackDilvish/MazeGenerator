#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include"Maze.h"

#define TILE_SIZE 25
#define W_MAX_WIDTH 1920
#define W_MAX_HEIGHT 1080

class Game
{
    public:
        Game();
        ~Game();

        void UpdateGame();
        void RenderGame();
        bool IsPlaying() const;

    private:

        void InitWindow(size_t width = W_MAX_WIDTH, size_t height = W_MAX_HEIGHT);
        std::pair<size_t, size_t> GetInputMazeDimensions() const;
        void Pollevents();

        Maze* _maze;
        sf::RenderWindow* _window;
};

#endif // GAME_H
