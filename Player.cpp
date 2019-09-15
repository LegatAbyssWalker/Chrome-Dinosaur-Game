#include "Player.h"

#include "MoreInfo.h"


Player::Player(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float jumpSpeed, float downSpeed)
	: Entity(*texture), animation{ texture, imageCount, switchTime }, jumpSpeed(jumpSpeed), downSpeed(downSpeed) {

	entity.setOrigin(entity.getGlobalBounds().width / 2, entity.getGlobalBounds().height / 2);
}

void Player::keyboardInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up || key == sf::Keyboard::Space) { jumping = isPressed; }
	if (key == sf::Keyboard::S || key == sf::Keyboard::Down) { crouching = isPressed; }

}

void Player::updatePlayer(bool manualAnimation) {
	//Movement/Animation
	sf::Vector2<float> playerMovement(0.f, 0.f);

	if (jumpTickSpeed < 35) {
		if (jumping) {
			jumpTickSpeed++;
			playerMovement.y -= jumpSpeed;
			setDirection(Animation::Direction::jumping); 
			moving = false; 
		}

		else if (crouching) {
			//TODO fix ground, player goes too fast into the ground
			playerMovement.y += downSpeed;
			setDirection(Animation::Direction::crouching);
			moving = true;
		}

		else {
			setDirection(Animation::Direction::running);  
			moving = true;

		}
	}


	//Gravity
	if (getY() < PLAYER_POSITION_Y && !jumping) {
		playerMovement.y += GRAVITY_SPEED;
		jumpTickSpeed--;
	}

	//Bounds
	if (getY() > PLAYER_POSITION_Y) {
		playerMovement.y -= downSpeed;
		jumpTickSpeed = 0;
	}

	//Tick speed regulation
	if (jumpTickSpeed <= 0) {
		jumpTickSpeed = 0;
	}


	animation.updateAnimation(manualAnimation, moving);
	entity.setTextureRect(animation.uvRect);
	entity.move(playerMovement);
}

void Player::setDirection(const Animation::Direction& direction) {
	animation.direction = direction;
}
