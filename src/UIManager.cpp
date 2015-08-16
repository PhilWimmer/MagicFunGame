#include "UIManager.h"


UIManager::UIManager()
{
}

void UIManager::setTerrain(sf::Sprite* t)
{
	terrain = t;
}

sf::Sprite* UIManager::getUI()
{
	(*terrain).setPosition(x, y);
	return terrain;
}


UIManager::~UIManager()
{
}
