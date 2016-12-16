#ifndef WINDOW_H
#define WINDOW_H
#include "draw.h"
#include <fstream>
#include <time.h>

class Window
{
    public:
        sf::RenderWindow window;
        Window();
        Play();
        Display();
        virtual ~Window();
        Window(const Window& other);

    protected:

    private:

         show_cards();
         sf::Event event;
         sf::Vector2i localPosition;
         Draw table, card1, card2, txt;
         char path1[1000], path2[1000], text[1000];
         int number_of_cards;
         struct
         {
             char M[60][60];
             int value[60];
         }cards;

};

#endif // WINDOW_H
