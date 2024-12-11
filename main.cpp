#include "pipe.h"
#include "player.h"
#include "playerInput.h"
#include"scoreHandler.h"
#include"pipeEntity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameplayState.h"

int main()
{
	enum game_states {
		Menu,
		Gameplay,
		Gameover
	};

	game_states _gameState = Gameplay;

	//TODO:
	// an update loop
	// a game state service that holds current state
	// update loop would 
	//Sounds

	sf::RenderWindow window(sf::VideoMode(600, 800), "Flappy Bird");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	ScoreHandler scoreHandler = ScoreHandler();
	Randomizer randomizer = Randomizer(-400, 400);

	std::ifstream inFile("score.txt");
	inFile >> scoreHandler;
	inFile.close();
	std::cout << scoreHandler.getScore();

	GameplayState _gameState2 = GameplayState(window, scoreHandler, randomizer);

	switch (_gameState)
	{
	case Menu:
		break;
	case Gameplay:
		_gameState2.Enter();
		break;
	case Gameover:
		break;
	default:
		break;
	}

	return 0;
}