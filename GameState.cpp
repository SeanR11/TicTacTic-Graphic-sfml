#include "GameState.h"
#include "Definitions.h"
#include "PauseState.h";
#include <iostream>

GameState::GameState(gameDataRef data) : _data(data) {

}

void GameState::Init() {

	this->_data->assets.loadFont("Font", FONT_PATH);

	this->_winText.setFont(this->_data->assets.getFont("Font"));

	this->_data->assets.loadTexture("Grid", GRID_PATH);
	this->_data->assets.loadTexture("Pause Button", PAUSE_BUTTON_PATH);
	this->_data->assets.loadTexture("Empty Cube", EMPTY_CUBE_PATH);
	this->_data->assets.loadTexture("X", X_PATH);
	this->_data->assets.loadTexture("O", O_PATH);
	this->_data->assets.loadTexture("X Win", X_WIN_PATH);
	this->_data->assets.loadTexture("O Win", O_WIN_PATH);
	this->_data->assets.loadTexture("Retry Button", RETRY_BUTTON_PATH);

	this->_grid.setTexture(this->_data->assets.getTexture("Grid"));
	this->_pauseButton.setTexture(this->_data->assets.getTexture("Pause Button"));
	this->_emptyCube.setTexture(this->_data->assets.getTexture("Empty Cube"));
	this->_retryButton.setTexture(this->_data->assets.getTexture("Retry Button"));
	
	this->_winText.setString("      ");
	this->_retryButton.setColor(Color(54, 57, 67));


	this->_grid.setPosition(SCREEN_WIDTH / 2 - _grid.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _grid.getGlobalBounds().height / 2);
	this->_pauseButton.setPosition(SCREEN_WIDTH - _pauseButton.getGlobalBounds().width, 0);
	this->_retryButton.setPosition(SCREEN_WIDTH - _pauseButton.getGlobalBounds().width - _retryButton.getGlobalBounds().width, 15);

	this->_winText.setPosition(SCREEN_WIDTH / 2 - this->_winText.getGlobalBounds().width, SCREEN_HEIGHT * 0.8 - this->_winText.getGlobalBounds().height / 2);

	InitGrid();
}

void GameState::InitGrid() {

	Vector2u tempSize = this->_data->assets.getTexture("Empty Cube").getSize();

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->_gridArray[x][y].setTexture(this->_data->assets.getTexture("Empty Cube"));
			this->_gridArray[x][y].setPosition(this->_grid.getPosition().x + (tempSize.x * x) - 7, this->_grid.getPosition().y + (tempSize.y * y) - 7);
			_gridStatus[x][y] = 0;
		}

	}
}

void GameState::HandleInput() {

	Event eve;

	while (this->_data->window.pollEvent(eve)) {


		if (Event::Closed == eve.type)
			this->_data->window.close();
		if (Event::MouseMoved == eve.type || Event::MouseEntered == eve.type) {
			eve.type = Event::MouseButtonReleased;
			break;
		}
		else if (this->_data->input.isSpriteClicked(_pauseButton, Mouse::Left, this->_data->window)) {
			this->_data->machine.AddState(stateRef(new PauseState(_data)), false);
			break;
		}
		else if (this->_data->input.isSpriteClicked(_retryButton, Mouse::Left, this->_data->window)) {
			this->_data->machine.RemoveState();
			this->_data->machine.AddState(stateRef(new GameState(_data)), false);
			break;

		}

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (this->_data->input.isSpriteClicked(_gridArray[x][y], Mouse::Left, this->_data->window) && _gridStatus[x][y] == 0) {
					if (turn == 1) {
						this->_gridArray[x][y].setTexture(this->_data->assets.getTexture("X"));
						turn = 2;
						_gridStatus[x][y] = 1;
						break;
					}
					if (turn == 2) {
						this->_gridArray[x][y].setTexture(this->_data->assets.getTexture("O"));
						turn = 1;
						_gridStatus[x][y] = 2;
						break;
					}
				}

			}
		}
	}


}

void GameState::Update(float dt) {


	this->tempWinner = this->_data->assets.getTexture("X Win");
	this->tempWinner2 = this->_data->assets.getTexture("O Win");

	
	for (int y = 0; y < 3; y++) {

			//0502616525
		if (_gridStatus[0][y] == 1 && _gridStatus[1][y] == 1 && _gridStatus[2][y] == 1) {
			this->_gridArray[0][y].setTexture(tempWinner);
			this->_gridArray[1][y].setTexture(tempWinner);
			this->_gridArray[2][y].setTexture(tempWinner);
			this->_winText.setString("X Win!");
			break;
		}
		else if (_gridStatus[y][0] == 1 && _gridStatus[y][1] == 1 && _gridStatus[y][2] == 1) {
			this->_gridArray[y][0].setTexture(tempWinner);
			this->_gridArray[y][1].setTexture(tempWinner);
			this->_gridArray[y][2].setTexture(tempWinner);
			this->_winText.setString("X Win!");
			break;
		}
		else if (_gridStatus[0][0] == 1 && _gridStatus[1][1] == 1 && _gridStatus[2][2] == 1) {
			this->_gridArray[0][0].setTexture(tempWinner);
			this->_gridArray[1][1].setTexture(tempWinner);
			this->_gridArray[2][2].setTexture(tempWinner);
			this->_winText.setString("X Win!");
			break;
		}
		else if (_gridStatus[2][0] == 1 && _gridStatus[1][1] == 1 && _gridStatus[0][2] == 1) {
			this->_gridArray[2][0].setTexture(tempWinner);
			this->_gridArray[1][1].setTexture(tempWinner);
			this->_gridArray[0][2].setTexture(tempWinner);
			this->_winText.setString("X Win!");
			break;
		}

		else	if (_gridStatus[0][y] == 2 && _gridStatus[1][y] == 2 && _gridStatus[2][y] == 2) {
			_gridArray[0][y].setTexture(tempWinner2);
			_gridArray[1][y].setTexture(tempWinner2);
			_gridArray[2][y].setTexture(tempWinner2);
			this->_winText.setString("O Win!");
			break;
		}
		else if (_gridStatus[y][0] == 2 && _gridStatus[y][1] == 2 && _gridStatus[y][2] == 2) {
			_gridArray[y][0].setTexture(tempWinner2);
			_gridArray[y][1].setTexture(tempWinner2);
			_gridArray[y][2].setTexture(tempWinner2);
			this->_winText.setString("O Win!");
			break;
		}
		else if (_gridStatus[0][0] == 2 && _gridStatus[1][1] == 2 && _gridStatus[2][2] == 2) {
			_gridArray[0][0].setTexture(tempWinner2);
			_gridArray[1][1].setTexture(tempWinner2);
			_gridArray[2][2].setTexture(tempWinner2);
			this->_winText.setString("O Win!");
			break;
		}
		else if (_gridStatus[2][0] == 2 && _gridStatus[1][1] == 2 && _gridStatus[0][2] == 2) {
			_gridArray[2][0].setTexture(tempWinner2);
			_gridArray[1][1].setTexture(tempWinner2);
			_gridArray[0][2].setTexture(tempWinner2);
			this->_winText.setString("O Win!");
			break;
		}

		
	}


}

void GameState::draw(float dt) {

	this->_data->window.clear();
	this->_data->window.draw(_grid);
	this->_data->window.draw(_pauseButton);
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->_data->window.draw(_gridArray[x][y]);
		}
	}
	this->_data->window.draw(_winText);
	this->_data->window.draw(_retryButton);
	this->_data->window.display();
}

