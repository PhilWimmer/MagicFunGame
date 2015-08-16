#include <SFML/Graphics.hpp>
#include "tile.h"
#include <iostream>
#include "Unit.h"
#include "textureManager.h"
#include "UIManager.h"

#include <thread>         
#include <chrono>

void testTextureManager(sf::RenderWindow*);

void testTextureManager(sf::RenderWindow* window_ptr) {

	TextureManager tex;
	tex.getFiles();
	tex.createTextures();

	sf::Texture texture;
	sf::Sprite* sprite = (new sf::Sprite(texture));

	for(std::vector<std::string>::iterator it = tex.fileNames.begin(); it != tex.fileNames.end(); ++it) {
    	std::string name = *it;

    	int dotPos = name.find_last_of('.');
    	name.erase(dotPos, name.length() - dotPos);
    	std::cout << name << std::endl;

    	sprite = (new sf::Sprite(tex.textureTable.at(name)));
    	window_ptr->clear();
    	window_ptr->draw(*sprite);
    	window_ptr->display();
    	std::this_thread::sleep_for (std::chrono::seconds(2));
    }
} 

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Test");
	sf::CircleShape shape(100.f); 
	shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	texture.loadFromFile("Sprites/Scene10x10.png");
	texture.setSmooth(true);
	sf::Sprite* sprite = (new sf::Sprite(texture));
	//(*sprite).setColor(sf::Color(128, 128, 128));

	Unit test_unit(10, 10, *sprite);
	Tile test(sprite, &test_unit);
	UIManager uimanager;
	uimanager.setTerrain(sprite);

	int mousex=0, mousey=0;

	//testTextureManager(&window); 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				mousex = sf::Mouse::getPosition().x;
				mousey = sf::Mouse::getPosition().y;

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseMoved)
			{
				uimanager.x += event.mouseMove.x-mousex;
				uimanager.y += event.mouseMove.y-mousey;
				mousex = event.mouseMove.x;
				mousey = event.mouseMove.y;
			}
			/* Zooming - Experimental
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				uimanager.scale = signbit(event.mouseWheelScroll.delta)?uimanager.scale*0.95:uimanager.scale*1.05;
			}*/
		}
		//UI Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			uimanager.y -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			uimanager.y += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			uimanager.x -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			uimanager.x += 1;
		if (sf::Mouse::getPosition().x < 20)
			uimanager.x -= 1;
		if (sf::Mouse::getPosition().x > 1900)
			uimanager.x += 1;
		if (sf::Mouse::getPosition().y < 20)
			uimanager.y -= 1;
		if (sf::Mouse::getPosition().y > 1060)
			uimanager.y += 1;

		
		window.clear();
		window.draw(*uimanager.getUI());
		//window.draw(*test.sprite);
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
