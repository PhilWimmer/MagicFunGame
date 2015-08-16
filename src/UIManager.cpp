#include "UIManager.h"


UIManager::UIManager()
{
}

void UIManager::setTerrain(sf::Sprite t)
{
	terrain = t;
	scale = t.getScale().x;
}

sf::Sprite* UIManager::getUI()
{
	terrain.setPosition(x, y);
	terrain.setScale(scale, scale);
	return &terrain;
}


UIManager::~UIManager()
{
}
