#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "Entity.h"

#include "Animation.h"
#include "ToggleKey.h"

#include "Cacti.h"

#include <iostream>
#include <chrono>

class Player : public Entity {
	public:
		Player(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float jumpSpeed, float downSpeed);

		void keyboardInputs(sf::Keyboard::Key key, bool isPressed);
		void updatePlayer(bool continuous);
		void setDirection(const Animation::Direction& direction);

	private:
		Animation animation;
		float jumpSpeed, downSpeed;

		int jumpTickSpeed;

		bool isOnGround;
		bool moving = false;
		bool jumping = false;
		bool crouching = false;
};

#endif