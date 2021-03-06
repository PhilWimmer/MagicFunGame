#pragma once
#include <SFML/Graphics.hpp>
#include "unitType.h"
#include "textureManager.h"
#include <queue>

class Unit
{

public:
	int maxAP;
	int currAP;
	int maxHP;
	int currHP;
	int x; 
	int y;
	std::queue<std::string> actionQ;	
	UnitType type;
	sf::Sprite sprite;
	Unit(int, int, sf::Sprite, TextureManager*, int xPos = 29, int yPos = 29, UnitType u = standard);
	Unit();
	~Unit();
};

