#include "Game.h"

Game::Game()
{
    srand(clock());

    auto input = GetInputMazeDimensions();
    InitWindow(input.first * TILE_SIZE, input.second * TILE_SIZE);

    _maze = new Maze(input.first, input.second, TILE_SIZE);
}

Game::~Game()
{
    delete _maze;
    delete _window;
}

std::pair<size_t, size_t> Game::GetInputMazeDimensions() const
{
    size_t width, height;

    do{
        std::cout<<"Podaj szerosc labiryntu: ";
    }while(std::cin>>width && (width*TILE_SIZE > W_MAX_WIDTH));

    do{
        std::cout<<"Podaj wysokosc labiryntu: ";
    }while(std::cin>>height && (height*TILE_SIZE > W_MAX_HEIGHT));

    return std::make_pair(width, height);
}

void Game::InitWindow(size_t width, size_t height)
{
    //Create window
    sf::VideoMode videomode;

    videomode.width = width;
    videomode.height = height;

    _window = new sf::RenderWindow(videomode, "Maze generator");
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

void Game::UpdateGame()
{
    Pollevents();

    _maze->UpdateMaze();

    RenderGame();
}

void Game::RenderGame()
{
    _window->clear();

    _maze->RenderMaze(*_window);

    _window->display();
}

bool Game::IsPlaying() const
{
    return _window->isOpen();
}
