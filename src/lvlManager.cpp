#include "lvlManager.h"


lvlManager::lvlManager()
{
	Tile map[30][30];
}

lvlManager::~lvlManager()
{
}

std::string lvlManager::buildKey(){
	return "";
}

void lvlManager::genMap(std::unordered_map<std::string, sf::Texture*> textures){
	for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			sf::Texture* tex = textures.at(lvlManager::buildKey());
			sf::Sprite sprite;
			sprite.setTexture(*tex);
			map[i][j].sprite = &sprite;
		}
	}
}

sf::Sprite lvlManager::genDrawable(){
	sf::RenderTexture texture;
	texture.create(3840, 3840);
	for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			sf::Sprite renderSprite = *(map[i][j].sprite);
			renderSprite.setPosition(i * 128, j * 128);
			texture.draw(renderSprite);
		}
	}
	sf::Texture tex = texture.getTexture();
	sf::Sprite outputSprite = *(new sf::Sprite(tex));
	return outputSprite;
}
