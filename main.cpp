#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "My window");

    // run the program as long as the window is open
    sf::Event event;
    sf::Vector2i localPosition;

    sf::Texture TableTexture;
    char path[]="cards_PNG/10_of_diamonds.png";
    if (!TableTexture.loadFromFile(path))
        cout<<"Eroare incarcare png!"<<'\n';

    sf::Sprite TableSprite;
    TableSprite.setTexture(TableTexture);
    int centredTableSprite_x=(window.getSize().x-TableSprite.getLocalBounds().width)/2;
    int centredTableSprite_y=(window.getSize().y-TableSprite.getLocalBounds().height)/2;
    TableSprite.setPosition(centredTableSprite_x, centredTableSprite_y);
    //TableSprite.setScale();


    /*sf::Texture CardTexture_1;
    if (!CardTexture_1.loadFromFile("10_of_clubs.png"))
        cout<<"Eroare incarcare png!"<<'\n';
    sf::Sprite CardSprite_1;
    CardSprite_1.setTexture(CardTexture_1);
    CardSprite_1.scale(.19f, .19f);
    CardSprite_1.setPosition(660, 500);*/



    cout<<window.getSize().x<<'\n';
    cout<<window.getSize().y<<'\n';
    cout<<TableSprite.getLocalBounds().width<<'\n';
    cout<<TableSprite.getLocalBounds().height<<'\n';


    window.clear();
    window.draw(TableSprite);
    //window.draw(CardSprite_1);
    window.display();

    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {

                    localPosition = sf::Mouse::getPosition(window);
                    cout<<"width: "<<localPosition.x<<'\n';
                    cout<<"height: "<<localPosition.y<<'\n';
                }
                else
                    window.close();
            }

            if (event.type == sf::Event::Closed)
            {
                    window.close();
            }

        }
    }
    return 0;
}
