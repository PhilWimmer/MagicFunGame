#pragma once
#include "textureManager.h"
#include "Unit.h"
#include "lvlManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

//Player does not extend but encapsulate Unit, for property access reasons
class Player {
public:
	Unit* playerUnit = NULL;
	sf::Sound bark;
	sf::SoundBuffer barkBuffer;
	Player(TextureManager* texMng, sf::SoundBuffer*, sf::Sprite s,int AP = 10, int HP = 30, int xPos = 0, int yPos = 15);
	~Player();
};
