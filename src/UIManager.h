#pragma once
#include <SFML/Graphics.hpp>
class UIManager
{
public:
	sf::Sprite terrain;
	sf::Sprite units;
	sf::Sprite outsprite;
	sf::Texture outtexture;
	float x=0, y=0;
	float scale;
	UIManager();
	~UIManager();
	void setTerrain(sf::Sprite);
	void setUnits(sf::Sprite t);
	sf::Sprite* getUnits();
	sf::Sprite* getUI();
	void drawEverything(sf::RenderWindow*);
};

