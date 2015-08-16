#include "Unit.h"
#include <iostream>

class Tile {
public:
	Tile();
	Tile(sf::Sprite*, Unit*);
	~Tile();
	sf::Sprite* sprite;
private:
	Unit* pawn = NULL;
};

