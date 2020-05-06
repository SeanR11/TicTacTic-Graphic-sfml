#pragma once
#include <SFML/Graphics.hpp>	
#include "State.h"
#include "Game.h"

class SplashState : public State {
public:
	SplashState(gameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void draw(float dt);

private:
	gameDataRef _data;
	Clock _clock;
	Sprite _background;

};

