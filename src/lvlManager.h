#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "textureManager.h"

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
private:
	std::string buildKey(TextureManager*);

};

