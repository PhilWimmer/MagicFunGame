#include "Unit.h"

	Unit::Unit(int mAP, int mHP, sf::Sprite s)
	{
		maxAP = mAP;
		currAP = mAP;
		maxHP = mHP;
		currHP = mHP;
		sprite = s;
	}


	Unit::~Unit()
	{
	}

