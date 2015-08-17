#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "textureManager.h"
#include "Tile.h"
#include <vector>
#include <string>

class lvlManager
{
public:
	Tile map[30][30];
	sf::Sprite output;
	sf::Texture tex;
	lvlManager();
	~lvlManager();
	void genMap(TextureManager*);
	void genDrawable(sf::Sprite*);
	std::vector<Tile> generateTiles(std::string, TextureManager*);
	void testTileGen(TextureManager*, sf::RenderWindow*);
private:
	std::string buildKey(TextureManager*);

};

