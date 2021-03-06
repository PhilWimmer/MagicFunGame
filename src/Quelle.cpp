#include <SFML/Graphics.hpp>
#include "tile.h"
#include <iostream>
#include "Unit.h"
#include "lvlManager.h"
#include "textureManager.h"
#include "UIManager.h"
#include <thread>         
#include <chrono>
#include "Player.h"
#include "UnitManager.h"
#include "AnimatedSprite.hpp"

void testTextureManager(sf::RenderWindow*);

void testTextureManager(sf::RenderWindow* window_ptr) {

	TextureManager tex;
	tex.getFiles();
	tex.createTextures();

	sf::Texture texture;
	sf::Sprite* sprite = (new sf::Sprite(texture));

	for(std::vector<std::string>::iterator it = tex.units.begin(); it != tex.units.end(); ++it) {
    	std::string name = *it;

    	int dotPos = name.find_last_of('.');
    	name.erase(dotPos, name.length() - dotPos);
    	std::cout << name << std::endl;

    	sprite = (new sf::Sprite(tex.textureTable.at(name)));
    	window_ptr->clear();
    	window_ptr->draw(*sprite);
    	window_ptr->display();
    	std::this_thread::sleep_for (std::chrono::seconds(1));
    }
} 

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Corgi Movement Simulator");
	/*sf::CircleShape shape(100.f); 
	shape.setFillColor(sf::Color::Green);*/

	/*sf::Texture texture;
	texture.loadFromFile("Sprites/Scene10x10.png");
	texture.setSmooth(true);
	sf::Sprite* sprite = (new sf::Sprite(texture));*/
	//(*sprite).setColor(sf::Color(128, 128, 128));

	//testlvlManager

	sf::Texture shibe;
	if (!shibe.loadFromFile("Sprites/Units/shibe_spread.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		return 1;
	}

	Animation shibe_idle;
	shibe_idle.setSpriteSheet(shibe);
	shibe_idle.addFrame(sf::IntRect(0, 0, 128, 128));
	shibe_idle.addFrame(sf::IntRect(128, 0, 128, 128));
	shibe_idle.addFrame(sf::IntRect(256, 0, 128, 128));
	shibe_idle.addFrame(sf::IntRect(384, 0, 128, 128));

	AnimatedSprite animatedShibe(sf::seconds(0.2), false, true);
	animatedShibe.setPosition(0,0);
	animatedShibe.play(shibe_idle);

	TextureManager texMng;
	texMng.getFiles();
	texMng.createTextures();

	lvlManager lvl;
	Block b = lvl.generateTiles(lvl.buildKey(&texMng), &texMng);
	lvl.genMap(b, 0, 15);
	for (int i = 0; i < 50; i++){
		Block b = lvl.generateTiles(lvl.buildKey(&texMng), &texMng);
		sf::Vector2<int> v = lvl.findNextSpot(b.x, b.y);
		if (v.x != -1)
			lvl.genMap(b, v.x, v.y);
	}

	SoundManager sM;
	sM.getFiles();
	sM.createSounds();

	Player p(&texMng, &(sM.soundTable.at("bark")), sf::Sprite());

	//Unit test_unit(10, 10, *sprite);
	//Tile test(sprite, &test_unit);
	sf::Sprite output;
	lvl.genDrawable(&output);
	UIManager uimanager;
	uimanager.setTerrain(output);
	//uimanager.setTerrain(lvl.genDrawable());
	int mousex=0, mousey=0;

	//lvl.testTileGen(&texMng, &window);

	//testTextureManager(&window);

	UnitManager uM(&lvl, &texMng, &p, &sM);
	uM.spawnUnit(doge, p.playerUnit->x + 1, p.playerUnit->y);
	uM.spawnUnit(turtle, p.playerUnit->x, p.playerUnit->y + 1);
	std::cout << p.playerUnit->x + 1 <<  p.playerUnit->y + 1 << std::endl;
	uM.gatherActions();

	sf::Clock frameClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				mousex = sf::Mouse::getPosition(window).x;
				mousey = sf::Mouse::getPosition(window).y;

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseMoved)
			{
				uimanager.x += event.mouseMove.x-mousex;
				uimanager.y += event.mouseMove.y-mousey;
				mousex = event.mouseMove.x;
				mousey = event.mouseMove.y;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
			{
				uM.gatherActions();
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Right)
			{
				std::cout << "clicked at " << sf::Mouse::getPosition(window).x-uimanager.x << " " << sf::Mouse::getPosition(window).y-uimanager.y << std::endl;
				//std::cout << "is accessible: " << lvl.isAccessible(sf::Mouse::getPosition(window).x - uimanager.x, sf::Mouse::getPosition(window).y - uimanager.y) << std::endl;
				int xPos = sf::Mouse::getPosition(window).x - uimanager.x;
				int yPos = sf::Mouse::getPosition(window).y - uimanager.y;
				//std::cout << lvl.map[xPos / 128][yPos / 128].pawn << std::endl;
				if (lvl.isAccessible(xPos, yPos)) {
					uM.interact(xPos/128, yPos/128, &p);
					std::cout << xPos/128 << yPos/128 << std::endl;
					
					std::cout << "great success !" << std::endl;
				} else
					std::cout << "no" << std::endl;
			}
			/* Zooming - Experimental
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				uimanager.scale = signbit(event.mouseWheelScroll.delta)?uimanager.scale*0.95:uimanager.scale*1.05;
			}*/
		}
		//UI Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			uimanager.y += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			uimanager.y -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			uimanager.x += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			uimanager.x -= 1;
		if (sf::Mouse::getPosition(window).x < 20)
			uimanager.x += 1;
		if (sf::Mouse::getPosition(window).x > 1900)
			uimanager.x -= 1;
		if (sf::Mouse::getPosition(window).y < 20)
			uimanager.y += 1;
		if (sf::Mouse::getPosition(window).y > 1060)
			uimanager.y -= 1;

		// lvl.genDrawable(&output);
		// UIManager uimanager;
		// uimanager.setTerrain(output);
		
		sf::Time frameTime = frameClock.restart();

		animatedShibe.update(frameTime);

		window.clear();
		//sf::Sprite output2;
		//lvl.drawUnits(&output);
		//uimanager.setUnits(output2);
		//window.draw(*(uimanager.getUI()));
		//window.draw(*(uimanager.getUnits()));
		uimanager.setUnits(uM.getUnits());
		uimanager.drawEverything(&window);
		window.draw(animatedShibe);
		//window.draw(*sprite);
		//window.draw(output);
		/*sf::Texture texture;
		texture.loadFromFile("Sprites\\PlayerChar.png");
		texture.setSmooth(true);
		sf::Sprite* sprite = (new sf::Sprite(texture));
		(*sprite).setColor(sf::Color(128, 128, 128));
		sprite.setTexture(texture);*/
		//window.draw(*sprite);
		//std::cout << "Current player AP: " << p.playerUnit->currAP << ". Max player AP: " << p.playerUnit->maxAP << "." << std::endl;
		window.display();
	}

	return 0;
}
