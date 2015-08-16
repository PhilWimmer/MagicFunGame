#include <unordered_map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager {
public:
	void getFiles();
	TextureManager();
	~TextureManager();
	void createTextures();
	std::vector<std::string> fileNames;
	std::unordered_map<std::string, sf::Texture> textureTable;
};