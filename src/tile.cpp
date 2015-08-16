#include "tile.h"

Tile::Tile(){
	sprite = NULL;
	pawn = NULL;
}

Tile::Tile(sf::Sprite* s, Unit* p) {

	sprite = s;
	pawn = p;
}

Tile::~Tile() {

}
