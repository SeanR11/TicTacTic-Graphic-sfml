#pragma once
#include "Definitions.h"
#include "Game.h"
#include "State.h"

class PauseState : public State
{
public:
	PauseState(gameDataRef data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void draw(float dt);
private:
	gameDataRef _data;

	Sprite _background, _homeButton, _resumeButton, _soundButton;

	int _soundStatus = 1;
};

