#include <SFML/Graphics.hpp>
#include "tile.h"
#include <iostream>
#include "Unit.h"
#include "textureManager.h"
#include "UIManager.h"



int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Test");
	sf::CircleShape shape(100.f); 
	shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	texture.loadFromFile("Sprites/PlayerChar.png");
	texture.setSmooth(true);
	sf::Sprite* sprite = (new sf::Sprite(texture));
	//(*sprite).setColor(sf::Color(128, 128, 128));

	Unit test_unit(10, 10, *sprite);
	Tile test(sprite, &test_unit);
	//UIManager uimanager;
	//uimanager.setTerrain(sprite);

	TextureManager tex;
	tex.getFiles();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		
		window.clear();
		//window.draw(uimanager.getUI);
		window.draw(*test.sprite);
		//window.draw(*sprite);
		/*sf::Texture texture;
		texture.loadFromFile("Sprites\\PlayerChar.png");
		texture.setSmooth(true);
		sf::Sprite* sprite = (new sf::Sprite(texture));
		(*sprite).setColor(sf::Color(128, 128, 128));
		sprite.setTexture(texture);*/
		//window.draw(*sprite);
		window.display();
	}

	return 0;
}
