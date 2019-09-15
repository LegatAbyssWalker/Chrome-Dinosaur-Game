#ifndef BACKGROUNDMANAGER_H
#define BACKGROUNDMANAGER_H

#include "State.h"

#include <iostream>
#include <array>

#include "Cloud.h"
#include "Random.h"

class BackgroundManager {
	public:
		BackgroundManager();

		void renderTo(sf::RenderWindow& window);
		void update();
		void addCloud();

	private:
		sf::Texture cloudTexture;
		std::vector<std::unique_ptr<Cloud>> cloudVector;

		int cloudHeight;
		Random<> randomHeight;
};

#endif