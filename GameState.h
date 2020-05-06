#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"


class GameState : public State
{
public:
	GameState(gameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void draw(float dt);

private:
	gameDataRef _data;

	int turn = 1;
	int _gridStatus[3][3];

	Sprite _grid, _pauseButton, _emptyCube, _retryButton, _gridArray[3][3];
	Text _winText;
	Texture tempWinner, tempWinner2;
	void InitGrid();
};

