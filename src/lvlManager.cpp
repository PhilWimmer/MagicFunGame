#include "lvlManager.h"
#include <iostream>


lvlManager::lvlManager()
{
}

lvlManager::~lvlManager()
{
}

std::string lvlManager::buildKey(TextureManager* texMng){
	std::string key;
	key = texMng->fileNames[2];
	std::cout << key << std::endl;
	int dotPos = key.find_last_of('.');
	key.erase(dotPos, key.length() - dotPos);
	return key;
}

void lvlManager::genMap(TextureManager* texMng){
	for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			std::string name = buildKey(texMng);
			map[i][j].sprite.setTexture(texMng->textureTable.at(name));
		}
	}
}

void lvlManager::genDrawable(sf::Sprite* output){
	sf::RenderTexture texture;
	texture.create(3840, 3840);
	for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			sf::Sprite renderSprite = (map[i][j].sprite);
			renderSprite.setPosition(i * 128, j * 128);
			texture.draw(renderSprite);
			//CharTexture prüfen/renderen
			if (map[i][j].pawn != NULL){
				renderSprite.setTexture(*(map[i][j].pawn->sprite.getTexture()));
				texture.draw(renderSprite);
			}
		}
	}
	sf::Sprite renderSprite = sf::Sprite();
	sf::Texture testTex = sf::Texture();
	testTex.loadFromFile("Sprites/EnemyChar.png");
	renderSprite.setTexture(testTex);
	renderSprite.setPosition(0, 128);
	texture.draw(renderSprite);
	tex = texture.getTexture();
	//output = *(new sf::Sprite(tex));
	//tex.loadFromFile("Sprites/Scene10x10.png");
	(*output).setTexture(tex);
	/*std::cout << (*output).getScale().x << std::endl;
	std::cout << (*output).getScale().y << std::endl;
	(*output).scale( 0.5, 2 );
	std::cout << (*output).getScale().x << std::endl;
	std::cout << (*output).getScale().y << std::endl;*/
	//return &output;
}


//TODO Tile Splitting Function
