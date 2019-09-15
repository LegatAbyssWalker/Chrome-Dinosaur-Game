#include "Bird.h"

#include "MoreInfo.h"

Bird::Bird(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed)
	: Entity(*texture), animation(texture, imageCount, switchTime), speed(speed) {

	animation.direction = Animation::Direction::jumping;
	entity.setTexture(*texture);
}

void Bird::update() {
	sf::Vector2<float> movement(0.f, 0.f);
	movement.x -= speed;

	animation.updateAnimation(true, true);
	entity.setTextureRect(animation.uvRect);
	entity.move(movement);
}

bool Bird::isOnScreen() {
	if (getX() >= 0) {
		return true;
	}
	return false;
}
