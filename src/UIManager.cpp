#include "UIManager.h"


UIManager::UIManager()
{
	outsprite = sf::Sprite();
	scale = 1;
}

void UIManager::setTerrain(sf::Sprite t)
{
	terrain = t;
	//scale = t.getScale().x;
	//terrain.setScale(scale, -scale);
	//terrain.setOrigin(0, terrain.getLocalBounds().height);
}

void UIManager::setUnits(sf::Sprite t)
{
	units = t;
	//scale = t.getScale().x;
	//units.setScale(scale, -scale);
	//units.setOrigin(0, units.getLocalBounds().height);
}

sf::Sprite* UIManager::getUI()
{
	terrain.setPosition(x, y);
	//units.setPosition(x, y);
	terrain.setScale(scale, -scale);
	//units.setScale(scale, -scale);
	terrain.setOrigin(0, terrain.getLocalBounds().height);
	//sf::RenderTexture texture;
	//texture.create(3840, 3840);
	//texture.draw(terrain);
	
	//texture.draw(units);
	//outtexture = texture.getTexture();
	//outsprite.setTexture(outtexture);
	//outsprite.setPosition(x, y);
	//outsprite.setScale(scale, -scale);
	
	//return &outsprite;
	return &terrain;
}

sf::Sprite* UIManager::getUnits()
{
	units.setPosition(x, y);
	units.setScale(scale, -scale);
	units.setOrigin(0, units.getLocalBounds().height);
	return &units;

}

void UIManager::drawEverything(sf::RenderWindow* window)
{
	window->draw(*getUI());
	//window->draw(getUnits());
}

UIManager::~UIManager()
{
}
