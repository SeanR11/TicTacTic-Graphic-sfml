#include "InputManager.h"

bool InputManager::isSpriteClicked(Sprite object, Mouse::Button btn, RenderWindow &window) {

	if (Mouse::isButtonPressed(btn)) {
		
		IntRect bounds(object.getPosition().x,object.getPosition().y,object.getGlobalBounds().width,object.getGlobalBounds().height);

		if(bounds.contains(GetMousePosition(window)))
			return true;

	}
	return false;
}

Vector2i InputManager::GetMousePosition(RenderWindow &window) {
	
	return Mouse::getPosition(window);

}
