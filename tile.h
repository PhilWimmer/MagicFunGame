#include "unit.h"
#include <iostream>

class Tile {
public:
	Tile(sf::Sprite*, Unit*);
	~Tile();
	sf::Sprite* sprite;
private:
	Unit* pawn = NULL;
};

Tile::Tile(sf::Sprite* s, Unit* p) {

	sprite = s;
	pawn = p;
}

Tile::~Tile() {

}
