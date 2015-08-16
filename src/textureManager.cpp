#include "TextureManager.h"
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

TextureManager::TextureManager() {
	fileNames = std::vector<std::string>();
	textureTable = std::unordered_map<std::string, sf::Texture*>();
}

TextureManager::~TextureManager() {

}

void TextureManager::createTextures() {
	
}

void TextureManager::getFiles() {
	DIR *curDir;
	struct dirent * dirEntry;
	curDir = opendir("Sprites/"); 
	  if (curDir) {
	    while ((dirEntry = readdir(curDir))) {
	        fileNames.push_back(dirEntry->d_name);
	        std::cout << fileNames.back() << std::endl;
	    }
		closedir(curDir);
	}
}