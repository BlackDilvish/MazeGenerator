#include "Game.h"

Game::Game()
{
    InitWindow();

    InitMaze(std::make_pair(6,7));
}

Game::~Game()
{
    delete _window;
}

void Game::InitWindow()
{
    sf::VideoMode videomode;

    videomode.width = 960;
    videomode.height = 720;

    _window = new sf::RenderWindow(videomode, "Maze generator");
    _window->setFramerateLimit(60);
}

void Game::InitMaze(std::pair<size_t, size_t> dimensions)
{
    float gridSize = 30.f;

    for(size_t i=0; i< dimensions.first * dimensions.second; i++)
        _mazeTiles.push_back(MazeTile(sf::Vector2f(gridSize, gridSize), sf::Vector2f((i%(dimensions.first))*gridSize, (i/dimensions.first)*gridSize)));

    _mazeTiles[0].Visit();

}

void Game::Pollevents()
{
    sf::Event event;

    while(_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _window->close();
    }
}

void Game::UpdateMaze()
{

}

void Game::UpdateGame()
{
    Pollevents();
    UpdateMaze();

    RenderGame();
}

void Game::RenderMaze()
{
    for(auto& tile : _mazeTiles)
        tile.Render(*_window);
}

void Game::RenderGame()
{
    _window->clear();

    RenderMaze();

    _window->display();
}

bool Game::IsPlaying() const
{
    return _window->isOpen();
}
