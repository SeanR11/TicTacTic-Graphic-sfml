#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"

class MenuState : public State
{
public:
	MenuState(gameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void draw(float dt);

private:
	gameDataRef _data;
	Clock _clock;
	Sprite _background, _playbtn, _playoutter, _title;

};

