#pragma once
#include <memory>
#include <string>
#include "SFML/Graphics.hpp"
#include "StateMachine.h"
#include "InputManager.h"
#include "AssetManager.h"

struct gameData {

	StateMachine machine;
	InputManager input;
	AssetManager assets;
	RenderWindow window;
};

typedef shared_ptr<gameData> gameDataRef;


class Game
{
public:
	Game(int width, int height, string title);

private:
	const float dt = 1.0f / 60.0f;
	Clock _clock;
	gameDataRef _data = make_shared<gameData>();

	void run();

};

