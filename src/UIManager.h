#pragma once
#include <SFML/Graphics.hpp>
#include "drawableUnit.h"
class UIManager
{
public:
	sf::Sprite terrain;
	std::vector<DrawableUnit> units;
	sf::Sprite outsprite;
	sf::Texture outtexture;
	float x=0, y=0;
	float scale;
	UIManager();
	~UIManager();
	void setTerrain(sf::Sprite);
	void setUnits(std::vector<DrawableUnit>);
	sf::Sprite* getUI();
	void drawEverything(sf::RenderWindow*);
	void drawUnits(sf::RenderWindow* window);
};

