#include "BackgroundManager.h"

#include "MoreInfo.h"

BackgroundManager::BackgroundManager() {
	cloudTexture.loadFromFile(CLOUD_T);

	for (int x = 0; x < 1; x++) {
		cloudVector.emplace_back(new Cloud(cloudTexture, CLOUD_SPEED));
		cloudVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CLOUD_HEIGHT_1));
	}
}

void BackgroundManager::renderTo(sf::RenderWindow& window) {
	for (auto& cloud : cloudVector) {
		cloud->renderTo(window);
	}
}

void BackgroundManager::update() {
	size_t clouds_to_add = 0;
	for (auto& cloud : cloudVector) {
		cloud->update();
		
		//Determines when a new cloud is added
		if (cloud->getX() == 380) {
			clouds_to_add++;
		}
	}


	for (size_t x = 0; x < clouds_to_add; x++) {
		addCloud();
	}

	//Removal of clouds when off the screen
	auto newEnd = std::remove_if(cloudVector.begin(), cloudVector.end(), [](std::unique_ptr<Cloud> & cloud) {
		return !cloud->isOnScreen();
	});
	cloudVector.erase(newEnd, cloudVector.end());
}

void BackgroundManager::addCloud() {
	cloudHeight = randomHeight.getInt(1, 3);

	std::unique_ptr<Cloud> cloud(new Cloud(cloudTexture, CLOUD_SPEED));
	switch (cloudHeight) {
		case 1: cloud->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CLOUD_HEIGHT_1)); break;
		case 2: cloud->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CLOUD_HEIGHT_2)); break;
		case 3: cloud->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CLOUD_HEIGHT_3)); break;
	}
	cloudVector.push_back(std::move(cloud));
}
