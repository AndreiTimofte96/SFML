#include "window.h"
#include <sstream>

Window::Window()
{
}

Window::Display()
{
    window.create(sf::VideoMode::getDesktopMode(), "Black Jack's Network");
    window.clear();
}

Window::show_cards() ///DEZORDINE TOTALA
{
    window.clear();
    ifstream fin("cards.txt");

    ///desenez masa de joc
    strcpy(path1, "Photos/table3ps.png");
    table.draw_table(window, path1);

    fin>>number_of_cards;
    for (int i=0; i<number_of_cards; i++)
    {
        fin>>cards.M[i];
        fin>>cards.value[i];
    }

    int first_card, second_card;

    srand(time(NULL));
    first_card=rand()%number_of_cards;
    second_card=rand()%number_of_cards;

    cout<<first_card<<" "<<second_card<<'\n';
    cout<<cards.M[first_card]<<" "<<cards.M[second_card]<<'\n';

    card1.draw_card(window, cards.M[first_card], 624, 406);
    card2.draw_card(window, cards.M[second_card], 670, 406);

    //if (first_card>=48 && 52>=first_card)

    ///int to string. Thanks Google
    int sum=cards.value[first_card] + cards.value[second_card];
    string Result;
    ostringstream convert;
    convert << sum;
    Result=convert.str();
    strcpy(path1, "Fonts/arial.ttf");
    txt.draw_text(window, path1, Result, 580, 405);

    window.display();
}

Window::Play()
{
    show_cards();

    while (window.isOpen())
    {
        /// check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))///afiseaza alta pereche de carti
                {
                    show_cards();
                }

                if (sf::Mouse::isButtonPressed(sf::Mouse::Right))///afiseaza coordonatele click-ului
                {
                    localPosition = sf::Mouse::getPosition(window);
                    cout<<"width: "<<localPosition.x<<'\n';
                    cout<<"height: "<<localPosition.y<<'\n';
                }

            }

            if (event.type == sf::Event::Closed) /// IESI ACASA!!
            {
                    window.close();
            }
        }
    }
}

Window::~Window()
{
    //dtor
}

Window::Window(const Window& other)
{
    //copy ctor
}
