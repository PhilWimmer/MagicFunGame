#pragma once
#include <SFML/Graphics.hpp>
#include "Unit.h"
#include "textureManager.h"
#include "lvlManager.h"
#include "Player.h"

Player::Player(TextureManager* texMng, sf::Sprite s,int AP, int HP, int xPos, int yPos){
	sf::Sprite sprite;
	sprite.setTexture(texMng->textureTable.at("corgi"));
	playerUnit = (new Unit(AP, HP, sprite, texMng, xPos, yPos));
} 

Player::~Player() {}

bool Player::move(int newX, int newY, lvlManager* lvl) {
	//lvl->map[playerUnit->x][playerUnit->y].pawn = NULL;	FIX FIX FIX FIX FIX FIX FIX FIX FIX 
	playerUnit->x = newX;
	playerUnit->y = newY;

	//lvl->map[playerUnit->x][playerUnit->y].pawn = playerUnit;
	//std::cout << x << std::endl;
	return false;
}