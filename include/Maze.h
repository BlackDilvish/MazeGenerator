#ifndef MAZE_H
#define MAZE_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<stack>
#include"MazeTile.h"

class Maze
{
    public:
        Maze(size_t width, size_t height, float size);
        ~Maze() = default;

        void UpdateMaze();
        void RenderMaze(sf::RenderTarget& window);

    protected:

    private:

        size_t Offtop(size_t x, size_t y) const { return _stack.top() + x + y*_mazeWidth; }
        std::vector<size_t> GetNeighbors() const;
        void VisitAvailableNeighbor(const std::vector<size_t>& neighbors);

        size_t _mazeWidth;
        size_t _mazeHeight;
        size_t _visitedTiles;

        std::vector<MazeTile> _mazeTiles;
        std::stack<size_t> _stack;
};

#endif // MAZE_H
