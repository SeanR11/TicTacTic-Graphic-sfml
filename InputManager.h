#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager{
public:
	InputManager() { }
	~InputManager(){ }

	bool isSpriteClicked(Sprite object, Mouse::Button btn, RenderWindow &window);
	Vector2i GetMousePosition( RenderWindow &window); 

};

