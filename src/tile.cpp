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

bool Tile::notePosition(int x_arr, int y_arr) {
	if (x < 0 || x > 29 || y < 0 || y > 29) 
		return false;
	x = x_arr;
	y = y_arr;
	return true;
}