#pragma once
#include "state.h"
#include"sfml/Graphics.hpp"
#include "StateMachine.h"
#include "Button.h"
class MenuState : 
	public State
{
public:
	MenuState(sf::RenderWindow& window, StateMachine& stateMachine);
	void Enter() override;
	void Update() override;
	void Exit() override;
private:
	StateMachine* _stateMachine;
	sf::RenderWindow* _window;
	sf::Texture* _backgroundSprite;
	sf::RectangleShape* _backgroundShape;
	Button* _playButton;
};

