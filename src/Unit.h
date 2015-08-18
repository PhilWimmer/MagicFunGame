#pragma once
#include <SFML/Graphics.hpp>

class Unit
{

public:
	int maxAP;
	int currAP;
	int maxHP;
	int currHP;
	int x; 
	int y;
	sf::Sprite sprite;
	Unit(int, int, sf::Sprite, int xPos = 29, int yPos = 29);
	~Unit();
};

