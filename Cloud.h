#ifndef CLOUD_H
#define CLOUD_H

#include "State.h"
#include "Entity.h"


class Cloud : public Entity {
	public:
		Cloud(sf::Texture& texture, int speed);

		void update();
		bool isOnScreen();

	private:
		int speed;
};

#endif
