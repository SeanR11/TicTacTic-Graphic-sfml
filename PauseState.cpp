#include "PauseState.h"
#include "MenuState.h"

PauseState::PauseState(gameDataRef data) : _data(data) {


}

void PauseState::Init() {

	this->_data->assets.loadTexture("Background", PAUSE_BACKGROUND_PATH);
	this->_data->assets.loadTexture("Resume Button", RESUME_BUTTON_PATH);
	this->_data->assets.loadTexture("Home Button", HOME_BUTTON_PATH);
	this->_data->assets.loadTexture("Sound On", SOUND_ON_PATH);
	this->_data->assets.loadTexture("Sound Off", SOUND_OFF_PATH);

	this->_background.setTexture(this->_data->assets.getTexture("Background"));
	this->_resumeButton.setTexture(this->_data->assets.getTexture("Resume Button"));
	this->_homeButton.setTexture(this->_data->assets.getTexture("Home Button"));
	this->_soundButton.setTexture(this->_data->assets.getTexture("Sound On"));

	float temp = 0.9f;
	this->_resumeButton.setScale(temp, temp);
	this->_homeButton.setScale(temp, temp);
	this->_soundButton.setScale(temp, temp);


	this->_background.setPosition(SCREEN_WIDTH / 2 - this->_background.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2);
	this->_resumeButton.setPosition(SCREEN_WIDTH / 2 - this->_resumeButton.getGlobalBounds().width /2 ,
		(SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2 )+ (this->_background.getGlobalBounds().height * 0.2 - _resumeButton.getGlobalBounds().height/2));
	this->_homeButton.setPosition(SCREEN_WIDTH / 2 - this->_homeButton.getGlobalBounds().width / 2,
		(SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2 )+ (this->_background.getGlobalBounds().height * 0.52 - _homeButton.getGlobalBounds().height/2));
	this->_soundButton.setPosition(SCREEN_WIDTH / 2 - this->_soundButton.getGlobalBounds().width / 2,
		(SCREEN_HEIGHT / 2 - this->_background.getGlobalBounds().height / 2) + (this->_background.getGlobalBounds().height * 0.8 - _soundButton.getGlobalBounds().height/2));





}

void PauseState::HandleInput() {

	Event eve;

	while (this->_data->window.pollEvent(eve)) {
		if (Event::Closed == eve.type)
			this->_data->window.close();
		if (this->_data->input.isSpriteClicked(_resumeButton, Mouse::Left, this->_data->window)) {
			this->_data->machine.RemoveState();
			break;
		}
		if (this->_data->input.isSpriteClicked(_homeButton, Mouse::Left, this->_data->window)) {
			this->_data->machine.RemoveState();
			this->_data->machine.AddState(stateRef(new MenuState(_data)));
			break;
		}
		if (this->_data->input.isSpriteClicked(_soundButton, Mouse::Left, this->_data->window)) {
			if (_soundStatus == 0) {
				_soundButton.setTexture(this->_data->assets.getTexture("Sound On"));
				_soundStatus = 1;
				break;
			}
			else if (_soundStatus == 1) {
				_soundButton.setTexture(this->_data->assets.getTexture("Sound Off"));
				_soundStatus = 0;
				break;
			}
		}
	}


}

void PauseState::Update(float dt) {


}

void PauseState::draw(float dt) {


	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_resumeButton);
	this->_data->window.draw(this->_homeButton);
	this->_data->window.draw(this->_soundButton);
	this->_data->window.display();

}
