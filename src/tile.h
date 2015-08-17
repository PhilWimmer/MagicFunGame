#pragma once
#include "Unit.h"

class Tile {
public:
	Tile();
	Tile(sf::Sprite, Unit*, bool);
	~Tile();
	sf::Sprite sprite;
	bool accessible;
	Unit* pawn = NULL;
};

