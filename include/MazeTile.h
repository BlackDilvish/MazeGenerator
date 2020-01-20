#ifndef MAZETILE_H
#define MAZETILE_H

#include<SFML/Graphics.hpp>
#include<iostream>

class MazeTile
{
    public:
        MazeTile(float size, sf::Vector2f position);
        ~MazeTile() = default;

        void Render(sf::RenderTarget& window);

        void EraseBorder(size_t dimension);
        void Visit();
        const bool Visited() const;

        enum
        {
            TOP,
            RIGHT,
            BOTTOM,
            LEFT,
        };

    private:

        void InitBorders(float size, sf::Vector2f position);

        bool _visited;

        sf::RectangleShape _shape;
        sf::RectangleShape _borders[4];
};

#endif // MAZETILE_H
