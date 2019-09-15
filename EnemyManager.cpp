#include "EnemyManager.h"

#include "MoreInfo.h"


EnemyManager::EnemyManager() {
	//Texture information
	entityTexture[0].loadFromFile(SMALL_CACTUS_T);
	entityTexture[1].loadFromFile(LARGE_CACTUS_T);
	entityTexture[2].loadFromFile(MULTIPLE_CACTUS_T);
	entityTexture[3].loadFromFile(BIRD_T);

	//Cacti information
	for (int x = 0; x < 1; x++) {
		cactiVector.emplace_back(new Cacti(entityTexture[0], CACTI_SPEED_LEVEL_1));
		cactiVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH, ENTITY_POSITION_Y));
	}


	//Bird information
	for (int x = 0; x < 1; x++) {
		birdVector.emplace_back(new Bird(&entityTexture[3], sf::Vector2<unsigned>(2, 1), 0.2, BIRD_SPEED));
		birdVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 10, BIRD_HEIGHT_1));
	}
}

void EnemyManager::renderTo(sf::RenderWindow& window) {
	for (auto& cacti : cactiVector) {
		cacti->renderTo(window);
	}

	for (auto& bird : birdVector) {
		bird->renderTo(window);
	}
}

void EnemyManager::update() {
	/*-------------------------------------------------------------------------------------------------------------------*/
	//Cacti information
	for (auto& cacti : cactiVector) {
		cacti->update();

		//Determines when new cacti is added
		if (cacti->getX() == SCREEN_WIDTH / 2) {
			randomCacti = random[0].getInt(0, 2);
			addCacti(randomCacti);
		}
	}

	//Removal of cacti from vector
	auto cactiEnd = std::remove_if(cactiVector.begin(), cactiVector.end(), [](std::unique_ptr<Cacti> & cacti) {
		return !cacti->isOnScreen();
	});
	cactiVector.erase(cactiEnd, cactiVector.end());


	/*-------------------------------------------------------------------------------------------------------------------*/
	//Bird information
	size_t birds_to_add = 0;
	for (auto& bird : birdVector) {
		bird->update();

		//Determines when a new bird is added
		if (bird->getX() == 100) {
			birds_to_add++;
		}
	}

	for (size_t x = 0; x < birds_to_add; x++) {
		randomBirdY = random[1].getInt(1, 3);

		addBird(randomBirdY);
	}


	//Removal of birds when off the screen
	auto birdEnd = std::remove_if(birdVector.begin(), birdVector.end(), [](std::unique_ptr<Bird> & bird) {
		return !bird->isOnScreen();
	});
	birdVector.erase(birdEnd, birdVector.end());
}

void EnemyManager::addCacti(unsigned int textureType) {
	std::unique_ptr<Cacti> cacti(new Cacti(entityTexture[textureType], CACTI_SPEED_LEVEL_1));
	cacti->setPosition(sf::Vector2<float>(SCREEN_WIDTH, ENTITY_POSITION_Y));
	cactiVector.push_back(std::move(cacti));
}

void EnemyManager::addBird(int entityHeight) {
	randomBirdX = random[2].getInt(1, 5);

	std::unique_ptr<Bird> bird(new Bird(&entityTexture[3], sf::Vector2<unsigned>(2, 1), 0.1, BIRD_SPEED));

	switch (entityHeight) {
		case 1: 
			switch (randomBirdX) {
				case 1: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 1, BIRD_HEIGHT_1)); break;
				case 2: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 2, BIRD_HEIGHT_1)); break;
				case 3: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 3, BIRD_HEIGHT_1)); break;
				case 4: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 4, BIRD_HEIGHT_1)); break;
			}
			break;

		case 2:
			switch (randomBirdX) {
				case 1: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 1, BIRD_HEIGHT_2)); break;
				case 2: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 2, BIRD_HEIGHT_2)); break;
				case 3: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 3, BIRD_HEIGHT_2)); break;
				case 4: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 4, BIRD_HEIGHT_2)); break;
			}
			break;

		case 3:
			switch (randomBirdX) {
				case 1: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 1, BIRD_HEIGHT_3)); break;
				case 2: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 2, BIRD_HEIGHT_3)); break;
				case 3: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 3, BIRD_HEIGHT_3)); break;
				case 4: bird->setPosition(sf::Vector2<float>(SCREEN_WIDTH * 4, BIRD_HEIGHT_3)); break;
			}
			break;
	}

	birdVector.push_back(std::move(bird));
}

bool EnemyManager::collision(sf::FloatRect bounds) {
	//Cacti collision
	for (auto& cacti : cactiVector) {
		if (cacti->getGlobalBounds().intersects(bounds)) {
			return true;
		}

		else {
			return false;
		}
	}

	//Bird collision
	for (auto& bird : birdVector) {
		if (bird->getGlobalBounds().intersects(bounds)) {
			return true;
		}

		else {
			return false;
		}
	}
}
