#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "textureManager.h"
#include "Tile.h"
#include <vector>
#include <string>
#include "block.h"


class lvlManager
{
public:
	Tile map[30][30];
	sf::Sprite output;
	sf::Texture tex;
	lvlManager();
	~lvlManager();
	void genMap(std::vector<Tile>);
	void genDrawable(sf::Sprite*);
<<<<<<< HEAD
	bool lvlManager::isAccessible(int, int);
	std::vector<Tile> generateTiles(std::string, TextureManager*);
=======
	Block generateTiles(std::string, TextureManager*);
>>>>>>> a8c1b65b19b37184793d69bdd12fa43e92c9017e
	void testTileGen(TextureManager*, sf::RenderWindow*);
private:
	std::string buildKey(TextureManager*);

};

