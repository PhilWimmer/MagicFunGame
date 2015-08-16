#include <SFML/Graphics.hpp>
#include "tile.h"
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Test");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Unit test_unit;
	Tile test("corgi.png", test_unit);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.draw(test.sprite);
		window.clear();
		sf::Texture texture;
		texture.loadFromFile("Sprites\\PlayerChar.png");
		texture.setSmooth(true);
		sf::Sprite* sprite = (new sf::Sprite(texture));
		(*sprite).setColor(sf::Color(128, 128, 128));
		//sprite.setTexture(texture);
		window.draw(*sprite);
		window.display();
	}

	return 0;
}
