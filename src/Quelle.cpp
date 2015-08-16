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
	texture.loadFromFile("Sprites/PlayerChar.png");
	texture.setSmooth(true);
	sf::Sprite* sprite = (new sf::Sprite(texture));
	//(*sprite).setColor(sf::Color(128, 128, 128));

	Unit test_unit(10, 10, *sprite);
	Tile test(sprite, &test_unit);
	//UIManager uimanager;
	//uimanager.setTerrain(sprite);

	testTextureManager(&window); 

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
