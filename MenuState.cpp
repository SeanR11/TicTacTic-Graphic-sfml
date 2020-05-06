#include "MenuState.h"
#include "Definitions.h"
#include "GameState.h"

#include <iostream>

MenuState::MenuState(gameDataRef data) : _data(data){

}

void MenuState::Init() {

	this->_data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_PATH);
	this->_data->assets.loadTexture("Play button", PLAY_BUTTON_PATH);
	this->_data->assets.loadTexture("Button outter", PLAY_BUTTON_OUTTER_PATH);
	this->_data->assets.loadTexture("Game Title", GAME_TITLE_PATH);

	this->_background.setTexture(this->_data->assets.getTexture("Background"));
	this->_playbtn.setTexture(this->_data->assets.getTexture("Play button"));
	this->_playoutter.setTexture(this->_data->assets.getTexture("Button outter"));
	this->_title.setTexture(this->_data->assets.getTexture("Game Title"));

	this->_title.setPosition(SCREEN_WIDTH / 2 - this->_title.getGlobalBounds().width / 2, this->_title.getGlobalBounds().width * 0.1);
	this->_playbtn.setPosition(SCREEN_WIDTH / 2 - this->_playbtn.getGlobalBounds().width / 2,  SCREEN_HEIGHT * 0.9 - this->_playbtn.getGlobalBounds().height);
	this->_playoutter.setPosition(SCREEN_WIDTH / 2 - this->_playoutter.getGlobalBounds().width / 2, SCREEN_HEIGHT * 0.9 - this->_playbtn.getGlobalBounds().height /2 );

}

void MenuState::HandleInput() {

	Event eve;
	while (this->_data->window.pollEvent(eve)) {

		if (Event::Closed == eve.type) {
			this->_data->window.close();
		}
		if (this->_data->input.isSpriteClicked(_playbtn, Mouse::Left, this->_data->window)) {
			this->_data->machine.AddState(stateRef(new GameState(_data)), false);
		}
	}



}

void MenuState::Update(float dt) {


}

void MenuState::draw(float dt) {

	this->_data->window.clear();
	this->_data->window.draw(_background);
	this->_data->window.draw(_playbtn);
	this->_data->window.draw(_playoutter);
	this->_data->window.draw(_title);
	this->_data->window.display();



}