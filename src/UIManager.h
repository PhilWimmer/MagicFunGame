#pragma once
#include <SFML/Graphics.hpp>
class UIManager
{
public:
	sf::Sprite* terrain = NULL;
	float x, y;
	float scale;
	UIManager();
	~UIManager();
	void setTerrain(sf::Sprite*);
	sf::Sprite* getUI();
};

