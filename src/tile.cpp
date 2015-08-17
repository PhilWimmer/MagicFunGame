#include "tile.h"

Tile::Tile(){
	sprite = sf::Sprite();
	pawn = NULL;
}

Tile::Tile(sf::Sprite s, Unit* p, bool b) {
	accessible = b;
	sprite = s;
	pawn = p;
}

Tile::~Tile() {

}
