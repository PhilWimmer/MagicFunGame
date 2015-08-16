#include "Unit.h"

class Tile {
public:
	Tile(sf::Sprite*, Unit*);
	~Tile();
	sf::Sprite* sprite;
private:
	Unit* pawn = NULL;
};

