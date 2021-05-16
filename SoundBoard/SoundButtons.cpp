#include "Soundbuttons.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


void Soundbuttons::Load(Sprite *buttons) {

    buttons[0].setTexture(L_button);
    buttons[0].setPosition(240, 400);


    for (int i = 1; i < 7; i++) {

        buttons[i].setTexture(button);
        buttons[i].setPosition(200, 92 + (i * 47));
    }

    for (int i = 7; i < 10; i++) {

        buttons[i].setTexture(button);
        buttons[i].setPosition(440, 92 + ((i - 6) * 47));
    }

}

void Soundbuttons::Draw(RenderWindow& window, Sprite* buttons) {

    for (int i = 0; i < 10; i++) {

        window.draw(buttons[i]);
    }

}