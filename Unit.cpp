#include "Unit.h"

/*class Unit{
public:
	int maxAP;
	int currAP;
	int maxHP;
	int currHP;
	sf::Sprite sprite;

	Unit(int, int, sf::Sprite);
};*/
	

	Unit::Unit(int mAP, int mHP, sf::Sprite s)
	{
		maxAP = mAP;
		currAP = mAP;
		maxHP = mHP;
		currHP = mHP;
		sprite = s;
	}


	//Unit::~Unit()
	//{
	//}

