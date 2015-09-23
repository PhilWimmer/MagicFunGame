#pragma once
#include "Unit.h"
// unit with highest ratio of max to current AP, if same, moves are simultaneously.
Unit::Unit(int mAP, int mHP, sf::Sprite s, TextureManager* texMng,int xPos, int yPos, UnitType u)
{
	maxAP = mAP;
	currAP = mAP;
	maxHP = mHP;
	currHP = mHP;
	
	sprite = s;

	sf::Sprite sp;

	switch (u) {
		case standard:
			sp.setTexture(texMng->textureTable.at("EnemyChar"));
			break;

		case doge:
			sp.setTexture(texMng->textureTable.at("shibe"));
			break;

		case turtle:
			sp.setTexture(texMng->textureTable.at("turtle"));
			break;
	}

	if (s.getTexture() == NULL)
	 	sprite = sp;
	
	x = xPos;
	y = yPos;
	type = u;
	actionQ = std::queue<std::string>();
}

Unit::Unit() {
	maxAP = 10;
	currAP = 8; //! should be 10, for test purposes
	maxHP = 15;
	currHP = 15;
	x = 29; 
	y = 29;
	type = standard;
	sprite = sf::Sprite();
}

Unit::~Unit()
{
}

