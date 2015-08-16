#include "TextureManager.h"
#include <sys/types.h>
#include <dirent.h>

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

void TextureManager::getFiles() {
	DIR *dirHandle;
	struct dirent * dirEntry;
	dirHandle = opendir("."); 
	  if (dirHandle) {
	    while (0 != (dirEntry = readdir(dirHandle))) {
	        puts(dirEntry->d_name);
	    }
		closedir(dirHandle);
	}
}