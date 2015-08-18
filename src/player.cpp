#pragma once
#include <SFML/Graphics.hpp>
#include "Unit.h"
#include "textureManager.h"
#include "lvlManager.h"
#include "player.h"

Player::Player(TextureManager* texMng, sf::Sprite s,int AP, int HP, int xPos, int yPos){
	sf::Sprite sprite;
	sprite.setTexture(texMng->textureTable.at("corgi"));
	playerUnit = (new Unit(AP, HP, sprite, texMng, xPos, yPos));

	barkBuffer = sf::SoundBuffer();
	barkBuffer.loadFromFile("Sounds/bark.ogg");
	bark = sf::Sound(barkBuffer);
	bark.setVolume(100);
} 

Player::~Player() {}

