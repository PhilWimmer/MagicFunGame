#pragma once
#include <SFML/Graphics.hpp>
#include "Unit.h"
#include "textureManager.h"
#include "lvlManager.h"
#include "Player.h"

Player::Player(TextureManager* texMng, sf::Sprite s,int AP, int HP, int xPos, int yPos){
	sf::Sprite sprite;
	sprite.setTexture(texMng->textureTable.at("corgi"));
	playerUnit = (new Unit(AP, HP, sprite));
	x = xPos;
	y = yPos;
} 

Player::~Player() {}

bool Player::move(int newX, int newY, lvlManager* lvl) {
	lvl->map[x][y].pawn = NULL;
	x = newX;
	y = newY;

	lvl->map[x][y].pawn = playerUnit;
	//std::cout << x << std::endl;
	return false;
}