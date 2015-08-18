#pragma once
#include "textureManager.h"
#include "Unit.h"
#include "lvlManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//Player does not extend but encapsulate Unit, for property access reasons
class Player {
public:
	Unit* playerUnit = NULL;
	//int x; 
	//int y;

	Player(TextureManager* texMng, sf::Sprite s,int AP = 10, int HP = 30, int xPos = 0, int yPos = 0);
	~Player();
	bool move(int newX, int newY, lvlManager* lvl);
};
