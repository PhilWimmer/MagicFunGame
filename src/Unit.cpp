#pragma once
#include "Unit.h"

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
}

Unit::Unit() {
	maxAP = 10;
	currAP = 10;
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

