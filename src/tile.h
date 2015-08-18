#pragma once
#include "Unit.h"

class Tile {
public:
	Tile();
	Tile(sf::Sprite, bool);
	~Tile();	
	sf::Sprite sprite;
	bool accessible = false;
	int x = NULL;
	int y = NULL;
	bool notePosition(int, int);
};

