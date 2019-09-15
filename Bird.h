#ifndef BIRD_H
#define BIRD_H

#include "State.h"
#include "Entity.h"
#include "Animation.h"

#include <iostream>

class Bird : public Entity {
	public:
		Bird(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed);
		
		void update();
		bool isOnScreen();

	private:
		Animation animation;
		int speed;
};

#endif