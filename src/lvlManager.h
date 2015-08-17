#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "textureManager.h"
<<<<<<< HEAD
#include <vector>
=======
#include "Tile.h"
#include <vector>
#include <string>
>>>>>>> 76d30595f65e3ecb0c9297c33131e2c7aceaa076

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
=======
	std::vector<Tile> generateTiles(std::string, TextureManager*);
	void testTileGen(TextureManager*, sf::RenderWindow*);
>>>>>>> 76d30595f65e3ecb0c9297c33131e2c7aceaa076
private:
	std::string buildKey(TextureManager*);

};

