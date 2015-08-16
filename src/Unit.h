#pragma once
#include <SFML/Graphics.hpp>

class Unit
{

public:
	int maxAP;
	int currAP;
	int maxHP;
	int currHP;
	sf::Sprite sprite;
	Unit(int, int, sf::Sprite);
	~Unit();
};

