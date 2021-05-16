#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace sf;

class Background
{
public:

	sf::Color colour;
	sf::RectangleShape rectangle;

	Background() {

		colour = Color(64, 68, 75);

	}
	void Load();

	void Draw(RenderWindow& window);
};