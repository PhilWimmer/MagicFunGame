#pragma once
#include "tile.h"
#include <unordered_map>
#include <SFML/Graphics.hpp>

class lvlManager
{
public:
	Tile** map;
	lvlManager();
	~lvlManager();
	std::string lvlManager::buildKey();
	void lvlManager::genMap(std::unordered_map<std::string, sf::Texture*>);
	sf::Sprite lvlManager::genDrawable();

};

