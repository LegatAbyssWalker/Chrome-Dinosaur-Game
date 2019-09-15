#include "PlayingState.h"

#include "State.h"
#include "StateMachine.h"
class StateMachine;

#include "MoreInfo.h"

PlayingState::PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace },
	versionText(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 30, 25, ARIAL_FONT, "Version 0.0", sf::Color(128, 128, 128)),
	fpsCounter(sf::Color(128, 128, 128)),
	playerScoreText(SCREEN_WIDTH - 250, 25, 25, ARIAL_FONT, sf::Color(128, 128, 128)),
	playerBestScoreText(SCREEN_WIDTH - 100, 25, 25, ARIAL_FONT, sf::Color(128, 128, 128)) {


	//Player information
	playerTexture.loadFromFile(PLAYER_T);
	player = std::make_unique<Player>(&playerTexture, sf::Vector2<unsigned>(2, 3), 0.1, PLAYER_JUMP_SPEED, PLAYER_DOWN_SPEED);
	player->setPosition(sf::Vector2<float>(SCREEN_WIDTH / 4, PLAYER_POSITION_Y));

	//Score system
	std::ifstream ifs("Information/ChromeGame.txt");
	if (ifs.is_open()) {
		ifs >> playerBestScore; //Score
	}
}


void PlayingState::updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::Escape) { machine.run(machine.buildState<MainMenuState>(machine, window, true)); }
}

void PlayingState::updateEvents() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				updateKeyboardInputs(sfEvent.key.code, true);
				player->keyboardInputs(sfEvent.key.code, true);

				break;

			case sf::Event::KeyReleased:
				updateKeyboardInputs(sfEvent.key.code, false);
				player->keyboardInputs(sfEvent.key.code, false);
				break;
		}
	}
}

void PlayingState::update() {
	/*-------------------------------------------------------------------------------------------------------------------*/
	//Generalized Updating
	fpsCounter.updateCounter();
	backgroundManager.update();
	enemyManager.update();
	player->updatePlayer(true);
	playerScoreText.updateOText("Score: ", playerScore);
	playerBestScoreText.updateOText("Best: ", playerBestScore);

	/*-------------------------------------------------------------------------------------------------------------------*/
	playerScore++;
	std::ofstream ofs("Information/ChromeGame.txt", std::ios::out | std::ios::trunc);

	//Player information
	if (enemyManager.collision(player->getGlobalBounds())) {
		ofs << playerScore << std::endl; //Score

		machine.run(machine.buildState<MainMenuState>(machine, window, true));
	}
}

void PlayingState::render() {
	window.clear(sf::Color::White);

	//Render items
	fpsCounter.renderTo(window);
	versionText.renderTo(window);

	backgroundManager.renderTo(window);
	enemyManager.renderTo(window);
	
	playerScoreText.renderTo(window);
	playerBestScoreText.renderTo(window);

	player->renderTo(window);


	window.display();
}
