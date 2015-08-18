#include "Unit.h"

	Unit::Unit(int mAP, int mHP, sf::Sprite s, int xPos, int yPos)
	{
		maxAP = mAP;
		currAP = mAP;
		maxHP = mHP;
		currHP = mHP;
		sprite = s;
		x = xPos;
		y = yPos;
	}


	Unit::~Unit()
	{
	}

