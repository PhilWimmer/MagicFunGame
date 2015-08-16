#include "unit.h"

class Tile {
public:
	Tile(std::string, Unit);
	~Tile();
	sf::Sprite sprite;
private:
	Unit pawn;
};

Tile::Tile(std::string path, Unit p) {
	sf::Texture tex;
	tex.loadFromFile(path);

	sf::Sprite s;
	s.setTexture(tex);

	sprite = s;
	pawn = p;
}

Tile::~Tile() {

}
