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
			sp.setTexture(texMng->textureTable.at("doge"));
			break;

		case turtle:
			sp.setTexture(texMng->textureTable.at("turtle"));
			break;
	}

	if (sp.getTexture() != NULL)
		s = sp;
	
	x = xPos;
	y = yPos;
	type = u;
}


Unit::~Unit()
{
}

