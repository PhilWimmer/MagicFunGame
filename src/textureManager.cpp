#include "TextureManager.h"
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

TextureManager::TextureManager() {
	fileNames = std::vector<std::string>();
	textureTable = std::unordered_map<std::string, sf::Texture>();
}

TextureManager::~TextureManager() {

}

void TextureManager::createTextures() {
	sf::Texture texture;

	for(std::vector<std::string>::iterator it = fileNames.begin(); it != fileNames.end(); ++it) {
    	std::string name = *it;
		texture.loadFromFile("Sprites/" + name);
		std::cout << "Sprites/" << name << std::endl;

    	int dotPos = name.find_last_of('.');
    	name.erase(dotPos, name.length() - dotPos);

    	textureTable.emplace(name, texture);
	}
}

void TextureManager::getFiles() {
	DIR *curDir;
	struct dirent * dirEntry;
	curDir = opendir("Sprites/"); 
	  if (curDir) {
	    while ((dirEntry = readdir(curDir))) {
	    	std::string name(dirEntry->d_name);
	        if (name[0] != '.')
	        	fileNames.push_back(name);
	    }
		closedir(curDir);
	}
}
