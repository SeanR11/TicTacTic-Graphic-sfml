#include "SplashState.h"
#include "Definitions.h"
#include "MenuState.h"
#include <sstream>
#include <iostream>

using namespace sf;

SplashState::SplashState(gameDataRef data) : _data( data) {


}

void SplashState::Init() {

	this->_data->assets.loadTexture("Splash background", SPLASH_BACKGROUND_FILE);
	_background.setTexture(this->_data->assets.getTexture("Splash background"));

}

void SplashState::HandleInput() {

	Event ent;
	while(this->_data->window.pollEvent(ent)) {
		if (Event::Closed == ent.type)
			this->_data->window.close();
	}
}

void SplashState::Update(float dt) {

	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_TIME) {
		//switch state;
		this->_data->machine.AddState(stateRef(new MenuState(this->_data)), true);
		return;
	}
}

void SplashState::draw(float dt) {

	this->_data->window.clear();
	this->_data->window.draw(_background);
	this->_data->window.display();

}

