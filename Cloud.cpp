#include "Cloud.h"

#include "MoreInfo.h"

Cloud::Cloud(sf::Texture& texture, int speed)
	: Entity(texture), speed(speed) {

	entity.setTexture(texture);
	entity.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Cloud::update() {
 	entity.move(-speed, 0);
}

bool Cloud::isOnScreen() {
	if (getX() >= 0) {
		return true;
	}
	return false;
}
