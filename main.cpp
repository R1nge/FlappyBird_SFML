#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameplayState.h"
#include "pipeEntity.h"
#include "scoreHandler.h"
#include "StateMachine.h"

enum class game_states {
	Menu,
	Gameplay,
	Gameover
};

int main()
{
	//TODO:
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

	StateMachine state_machine = StateMachine();
	GameplayState _gamePlayState = GameplayState(window, scoreHandler, randomizer);
	state_machine.AddState(&_gamePlayState, game_states::Gameplay);

	state_machine.SwitchState(game_states::Gameplay);


	
	return 0;
}