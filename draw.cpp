#include "draw.h"

Draw::Draw()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "Black Jack's Network");

}

Draw::~Draw()
{
    //dtor
}

Draw::Draw(const Draw& other)
{
    //copy ctor
}
