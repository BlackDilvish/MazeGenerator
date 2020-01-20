#include "Maze.h"

Maze::Maze(size_t width, size_t height, float size)
{
    //Set maze's dimensions
    _mazeWidth = width;
    _mazeHeight = height;
    _visitedTiles = 0;

    float gridSize = size;

    for(size_t i=0; i< _mazeWidth * _mazeHeight; i++)
        _mazeTiles.push_back(MazeTile(gridSize, sf::Vector2f((i%(_mazeWidth))*gridSize, (i/_mazeWidth)*gridSize)));

    //Choose starting tile
    _stack.push(rand() % _mazeTiles.size());
    _mazeTiles[_stack.top()].Visit();
    _visitedTiles++;

}

void Maze::UpdateMaze()
{
    //Do next move if there is any tile left
    if(_visitedTiles < _mazeHeight * _mazeWidth)
    {
        auto neighbors = GetNeighbors();

        //Visit random neighbor if any is unvisited
        if(neighbors.size() > 0)
            VisitAvailableNeighbor(neighbors);
        else
            _stack.pop();
    }
}


std::vector<size_t> Maze::GetNeighbors() const
{
    std::vector<size_t> neighbours;

    if(_stack.top()/_mazeWidth > 0  &&  !_mazeTiles[Offtop(0, -1)].Visited())
            neighbours.push_back(MazeTile::TOP);
    if(_stack.top()%_mazeWidth < _mazeWidth-1  &&  !_mazeTiles[Offtop(1, 0)].Visited())
            neighbours.push_back(MazeTile::RIGHT);
    if(_stack.top()/_mazeWidth < _mazeHeight-1  &&  !_mazeTiles[Offtop(0, 1)].Visited())
            neighbours.push_back(MazeTile::BOTTOM);
    if((_stack.top()%_mazeWidth > 0)  &&  !_mazeTiles[Offtop(-1, 0)].Visited())
            neighbours.push_back(MazeTile::LEFT);

    return neighbours;
}

void Maze::VisitAvailableNeighbor(const std::vector<size_t>& neighbors)
{
    size_t chosenNeighbor = neighbors[rand() % neighbors.size()];
    _mazeTiles[_stack.top()].EraseBorder(chosenNeighbor);

    switch(chosenNeighbor)
    {
    case MazeTile::TOP:
        _stack.push(Offtop(0, -1));
        _mazeTiles[_stack.top()].EraseBorder(MazeTile::BOTTOM);

        break;
    case MazeTile::RIGHT:
        _stack.push(Offtop(1, 0));
        _mazeTiles[_stack.top()].EraseBorder(MazeTile::LEFT);

        break;
    case MazeTile::BOTTOM:
        _stack.push(Offtop(0, 1));
        _mazeTiles[_stack.top()].EraseBorder(MazeTile::TOP);

        break;
    case MazeTile::LEFT:
        _stack.push(Offtop(-1, 0));
        _mazeTiles[_stack.top()].EraseBorder(MazeTile::RIGHT);

        break;
    default:
        std::cout<<"ERROR::VisitAvailableNeighbor(const std::vector<size_t>&)\n";
        break;
    }

    _mazeTiles[_stack.top()].Visit();
    _visitedTiles++;
}

void Maze::RenderMaze(sf::RenderTarget& window)
{
    //Draw all tiles on screen
    for(auto& tile : _mazeTiles)
        tile.Render(window);
}
