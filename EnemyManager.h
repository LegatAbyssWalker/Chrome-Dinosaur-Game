#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "State.h"

#include <iostream>
#include <array>

#include "Random.h"
#include "Cacti.h"
#include "Bird.h"

class EnemyManager {
	public:
		EnemyManager();
		
		void renderTo(sf::RenderWindow& window);
		void update();
		
		void addCacti(unsigned int textureType);
		void addBird(int entityHeight);
		
		bool collision(sf::FloatRect bounds);

	private:
		int randomCacti, randomBirdX, randomBirdY;

		std::vector<std::unique_ptr<Cacti>> cactiVector;
		std::vector<std::unique_ptr<Bird>> birdVector;

		std::array<Random<>, 3> random;
		std::array<sf::Texture, 4> entityTexture;
};

#endif