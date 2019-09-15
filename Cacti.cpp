#include "Cacti.h"

#include "MoreInfo.h"

Cacti::Cacti(sf::Texture& texture, int speed) 
	: Entity(texture), speed(speed) {

	entity.setTexture(texture);
	entity.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Cacti::update() {
	entity.move(-speed, 0);
}

bool Cacti::isOnScreen() {
	if (getX() >= 0) {
		return true;
	}
	return false;
}
