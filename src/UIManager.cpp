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
	/*terrain.setPosition(x, y);
	units.setPosition(x, y);
	terrain.setScale(scale, -scale);
	units.setScale(scale, -scale);*/
	sf::RenderTexture texture;
	texture.create(terrain.getLocalBounds().width, terrain.getLocalBounds().height);
	texture.draw(terrain);
	//texture.draw(units);
	outtexture = texture.getTexture();
	outsprite.setTexture(outtexture);
	outsprite.setPosition(x, y);
	outsprite.setScale(scale, -scale);
	outsprite.setOrigin(0, outsprite.getLocalBounds().height);
	return &outsprite;
}


UIManager::~UIManager()
{
}
