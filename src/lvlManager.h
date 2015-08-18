#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "textureManager.h"
#include "Tile.h"
#include <vector>
#include <string>
#include "block.h"
#include "Unit.h"
#include "drawableUnit.h"

class lvlManager
{
public:
	Tile map[30][30];
	sf::Sprite output;
	sf::Texture tex;
	sf::Texture unitTex;
	sf::Sprite unitRenderSprite;
	sf::RenderTexture unitRenderTex;
	lvlManager();
	~lvlManager();
	void genMap(Block, int, int);
	void genDrawable(sf::Sprite*);
	bool isAccessible(int, int);
	Block generateTiles(std::string, TextureManager*);
	void testTileGen(TextureManager*, sf::RenderWindow*);
	std::string buildKey(TextureManager*);
	sf::Vector2<int> findNextSpot(int, int);
};

