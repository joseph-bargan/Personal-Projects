#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace sf;

class Texts {
public:
	sf::Font TMR;

	Texts() {

		if (!TMR.loadFromFile("times.ttf"))
		{
			std::cout << "Error code " << GetLastError();
		}
	}

	void Load(sf::Text *ta);
	void Draw(RenderWindow& window, Text* ta);
};