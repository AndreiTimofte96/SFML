#include "draw.h"

Draw::Draw()
{
}

Draw::draw_table(sf::RenderWindow &window, char path[])///table
{
    if (!texture.loadFromFile(path))
        cout<<"Eroare incarcare png!"<<'\n';

    sprite.setTexture(texture);
    int centredSprite_x=(window.getSize().x-sprite.getLocalBounds().width)/2;
    int centredSprite_y=(window.getSize().y-sprite.getLocalBounds().height)/2;

    sprite.setPosition(centredSprite_x, centredSprite_y);
    window.draw(sprite);
}

Draw::draw_card(sf::RenderWindow &window, char path[], int x, int y)///cards
{
    if (!texture.loadFromFile(path))
        cout<<"Eroare incarcare png!"<<'\n';

    sprite.setTexture(texture);
    sprite.setScale(0.23, 0.23);
    sprite.setPosition(x, y);
    window.draw(sprite);

}

Draw::draw_text(sf::RenderWindow &window, char path[], string s, int x, int y)///text
{
    if (!font.loadFromFile(path))
        cout<<"Eroare incarcare font!"<<'\n';

    text.setFont(font);
    text.setString(s);
    text.setCharacterSize(30); ///in pixels, not points!
    text.setColor(sf::Color::Cyan);
    text.setPosition(x, y);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(text);
}

Draw::~Draw()
{
    //dtor
}

Draw::Draw(const Draw& other)
{
    //copy ctor
}
