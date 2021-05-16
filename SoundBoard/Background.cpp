#include "Background.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void Background:: Load() {

	rectangle.setSize(sf::Vector2f(479.f, 479.f));
	rectangle.setFillColor(colour);
}

void Background::Draw(RenderWindow &window) {

	window.draw(rectangle);
}