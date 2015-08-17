#pragma once
#include "Unit.h"

class Tile {
public:
	Tile();
	Tile(sf::Sprite, Unit*);
	~Tile();
	sf::Sprite sprite;
	Unit* pawn = NULL;
};

