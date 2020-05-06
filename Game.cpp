#include "Game.h"
#include "SplashState.h"

using namespace sf;

Game::Game(int width, int height, string title) {

	_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);

	_data->machine.AddState(stateRef(new SplashState(this->_data)));
	this->run();

}

void Game::run() {

	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen()) {


		this->_data->machine.ProccedStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f)
			frameTime = 0.25f;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= this->dt) {
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(this->dt);
			accumulator -= this->dt;
		}

		interpolation = accumulator / this->dt;
		this->_data->machine.GetActiveState()->draw(this->dt);
	}
}
