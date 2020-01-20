#include "MazeTile.h"

MazeTile::MazeTile(float size, sf::Vector2f position)
    : _visited(false), _shape(sf::RectangleShape(sf::Vector2f(size, size)))
{
    _shape.setPosition(position);
    _shape.setFillColor(sf::Color::Blue);

    InitBorders(size, position);
}

void MazeTile::InitBorders(float size, sf::Vector2f position)
{
    _borders[TOP].setSize(sf::Vector2f(size * 1.1f, size * 0.1f));
    _borders[TOP].setPosition(position);

    _borders[RIGHT].setSize(sf::Vector2f(size * 0.1f, size * 1.1f));
    _borders[RIGHT].setPosition(position + sf::Vector2f(size, 0));

    _borders[BOTTOM].setSize(sf::Vector2f(size * 1.1f, size * 0.1f));
    _borders[BOTTOM].setPosition(position + sf::Vector2f(0, size));

    _borders[LEFT].setSize(sf::Vector2f(size * 0.1f, size * 1.1f));
    _borders[LEFT].setPosition(position);

    for(auto& border : _borders)
        border.setFillColor(sf::Color::Black);
}

void MazeTile::Render(sf::RenderTarget& window)
{
    window.draw(_shape);

    for(auto& border : _borders)
        window.draw(border);
}

void MazeTile::EraseBorder(size_t dimension)
{
    _borders[dimension].setFillColor(sf::Color::White);
}

void MazeTile::Visit()
{
    _visited = true;
    _shape.setFillColor(sf::Color::White);
}

const bool MazeTile::Visited() const
{
    return _visited;
}
