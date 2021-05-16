#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace sf;

class Soundbuttons
{
public:

	sf::Texture L_button;
	sf::Texture button;

	Soundbuttons() {

		if (!L_button.loadFromFile("Load_button.png")) {
			std::cout << "Error code " << GetLastError();
		}
		if (!button.loadFromFile("button.png")) {
			std::cout << "Error code " << GetLastError();
		}

	}

	void Load(Sprite* buttons);


	void Draw(RenderWindow& window, Sprite* buttons);

private:
	Text buttons;
};