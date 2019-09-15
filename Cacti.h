#ifndef CACTI_H
#define CACTI_H

#include "State.h"

#include <iostream>

#include "Entity.h"
#include "Random.h"

class Cacti : public Entity {
	public:
		Cacti(sf::Texture& texture, int speed);

		void update();
		bool isOnScreen();

	private:
		Random<> randomCacti;
		int chosenCacti, speed;
};

#endif