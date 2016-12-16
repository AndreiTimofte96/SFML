#ifndef DRAW_H
#define DRAW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstring>
#include <iostream>

using namespace std;

class Draw
{
    public:

        Draw();
        draw_table(sf::RenderWindow &window, char path[]);
        draw_card(sf::RenderWindow &window, char path[], int, int);
        draw_text(sf::RenderWindow &window,  char path[], string, int, int);
        Display();
        virtual ~Draw();
        Draw(const Draw& other);

    protected:

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2i localPosition;
        sf::Text text;
        sf::Font font;

};
#endif // DRAW_H
