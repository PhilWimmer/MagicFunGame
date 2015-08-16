#pragma once
#include <SFML/Graphics.hpp>
class UIManager
{
public:
	sf::Sprite terrain;
	float x=0, y=0;
	float scale;
	UIManager();
	~UIManager();
	void setTerrain(sf::Sprite);
	sf::Sprite* getUI();
};

