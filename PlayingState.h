#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "FPSCounter.h"
#include "Text.h"
#include "MoreInfo.h"
#include "Random.h"
#include "OStringText.h"

#include "Player.h"
#include "EnemyManager.h"
#include "BackgroundManager.h"

#include "State.h"
#include "MainMenuState.h"
class StateMachine;

#include <iostream>
#include <fstream>
#include <ostream>
#include <array>
#include <memory>

class PlayingState : public State {
	public:
		PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

		void updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed);

		void updateEvents();
		void update();
		void render();

	private:
		//Variables and Booleans
		int playerScore = 0;
		int playerBestScore = 0;

		//Arrays


		
		//Vectors
		

		//Class objects
		std::unique_ptr<Player> player = nullptr;

		BackgroundManager backgroundManager;
		EnemyManager enemyManager;
		FPSCounter fpsCounter;
		Text versionText;
		OStringText playerScoreText, playerBestScoreText;


		//SFML
		sf::Event sfEvent;
		sf::Texture playerTexture;
		sf::Clock dtClock;
		float	  dtTimer;
};

#endif