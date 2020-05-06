#include "AssetManager.h"


void AssetManager::loadTexture(string name, string fileName) {

	Texture temp;
	if(temp.loadFromFile(fileName))
	this->_textures[name] = temp;

}

void AssetManager::loadFont(string name, string fileName) {

	Font temp;
	if (temp.loadFromFile(fileName))
		this->_fonts[name] = temp;

}

Texture &AssetManager::getTexture(string name) {

	return this->_textures[name];
}

Font &AssetManager::getFont(string name) {
	
	return this->_fonts[name];

}