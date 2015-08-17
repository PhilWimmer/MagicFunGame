#include "lvlManager.h"
#include <iostream>
#include <thread>         
#include <chrono>

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
<<<<<<< HEAD

=======
}


//Only for rectangular blocks now
std::vector<Tile> lvlManager::generateTiles(std::string name, TextureManager* texMng) {
	std::vector<Tile> tiles;
	sf::Texture block = texMng->textureTable.at(name);

	//Split string, get size, create amount of tiles with textures, set their subrects
	int x = 0;
	int y = 0;
	
	int first_ = name.find('_');
	x = std::stoi(name.substr(first_ + 1, 1)); // This is going to crash and burn if blocks are ever 
	y = std::stoi(name.substr(first_ + 3, 1)); // larger than 9
	
	sf::Vector2u blockSize = block.getSize();
	//std::cout << block.getSize().x << " , " << block.getSize().y << std::endl; //128 x 128

	for (int x = 0; x < blockSize.x; x += 128) {
		for (int y = 0; y < blockSize.y; y += 128) {
			Tile t;
			sf::Sprite s;
			s.setTexture(texMng->textureTable.at(name));
			sf::Rect<int> rekt(x, y, 128, 128);
			s.setTextureRect(rekt);
			t.sprite = s;
			tiles.push_back(t);
			std::cout << x << " , " << y << std::endl;
		}
	}

	//std::cout << name.substr(first_ + 1, 1) << std::endl; //rtfm you retard

	return tiles;
}

void lvlManager::testTileGen(TextureManager* texMng, sf::RenderWindow* window_ptr) {
	if (!texMng->hasLoaded) {
		std::cout << "textures not loaded" << std::endl;
		return;
	}
	std::vector<Tile> tiles = generateTiles("test_2_4", texMng);
	for(std::vector<Tile>::iterator it = tiles.begin(); it != tiles.end(); ++it) {
    	it->sprite.getTextureRect();
    	window_ptr->clear();
    	window_ptr->draw(it->sprite);
    	window_ptr->display();
    	std::this_thread::sleep_for (std::chrono::seconds(1));
    }
>>>>>>> 76d30595f65e3ecb0c9297c33131e2c7aceaa076
}

bool lvlManager::isAccessible(int x, int y){
	return map[x / 128][y / 128].accessible;
}

