#include "Texts.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


void Texts::Load(Text *ta) {

    ta[0].setFont(TMR);
    ta[0].setCharacterSize(24);
    ta[0].setString("Load Sound Files");
    ta[0].setPosition(0, 0);


    for (int i = 1; i < 7; i++) {

        ta[i].setFont(TMR);
        ta[i].setCharacterSize(24);
        ta[i].setString("Numpad" + to_string(i) + ": ");
        ta[i].setPosition(10, 92 + (i*47));
    }

    for (int i = 7; i < 10; i++) {

        ta[i].setFont(TMR);
        ta[i].setCharacterSize(24);
        ta[i].setString("Numpad" + to_string(i) + ": ");
        ta[i].setPosition(230, 92 + ((i - 6) * 47));
    }

}

void Texts::Draw(RenderWindow& window, Text* ta) {

    for (int i = 0; i < 10; i++) {

        window.draw(ta[i]);
    }

}