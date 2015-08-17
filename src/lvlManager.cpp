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
	int length = texMng->fileNames.size();
	int pick = rand() % length;
	key = texMng->fileNames[pick];
	int dotPos = key.find_last_of('.');
	key.erase(dotPos, key.length() - dotPos);
	std::cout << key << std::endl;
	return key;
}

void lvlManager::genMap(std::vector<Tile> tiles){
	srand(time(NULL));
	/*for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			std::string name = buildKey(texMng);
			map[i][j].sprite.setTexture(texMng->textureTable.at(name));
		}
	}*/
	int count = 0;
	for (int j = 0; j <  blockwidth; j++){
		for (int i = 0; i < blockheight; i++){
			map[i][j] = tiles[count];
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
			//Leere Tiles auf inaccessible setzten und blocked textur verwenden
			if (map[i][j].sprite.getTexture() == NULL){
				sf::Texture tex = sf::Texture();
				tex.loadFromFile("Sprites/TileBlocked.png");
				map[i][j].sprite.setTexture(tex);
				renderSprite.setTexture(tex);
				texture.draw(renderSprite);
				map[i][j].accessible = false;
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
	(*output).setTexture(tex);

}

bool lvlManager::isAccessible(int x, int y){
	return map[x / 128][y / 128].accessible;
}

