#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameplayState.h"
#include "pipeEntity.h"
#include "scoreHandler.h"
#include "StateMachine.h"
#include "MenuState.h"
#include "GameoverState.h"

int main()
{
	//TODO:
	//Sounds

	sf::RenderWindow window(sf::VideoMode(600, 800), "Flappy Bird");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	ScoreHandler scoreHandler = ScoreHandler();
	Randomizer randomizer = Randomizer(-400, 400);

	//TODO: loader/saver class
	std::ifstream inFile("score.txt");
	inFile >> scoreHandler;
	inFile.close();
	std::cout << scoreHandler.getScore();

	StateMachine state_machine = StateMachine();
	MenuState _menuState = MenuState(window, state_machine);
	state_machine.AddState(&_menuState, game_states::Menu);
	GameplayState _gamePlayState = GameplayState(window, scoreHandler, randomizer, state_machine);
	state_machine.AddState(&_gamePlayState, game_states::Gameplay);
	GameoverState _gameoverState = GameoverState(window, state_machine, scoreHandler);
	state_machine.AddState(&_gameoverState, game_states::Gameover);

  	state_machine.SwitchState(game_states::Menu);

	while (window.isOpen())
	{
		state_machine.Update();
	}
	
	return 0;
}