#pragma once
#include "state.h"
#include "sfml/Graphics.hpp"
#include "StateMachine.h"
#include "Button.h"
#include "scoreHandler.h"


class GameoverState :
    public State
{
public:
	GameoverState(sf::RenderWindow& window, StateMachine& stateMachine, ScoreHandler& scoreHandler);
	void Enter() override;
	void Update() override;
	void Exit() override;
private:
	StateMachine* _stateMachine;
	sf::RenderWindow* _window;
	std::unique_ptr<sf::Texture> _backgroundSprite;
	std::unique_ptr<sf::RectangleShape> _backgroundShape;
	std::unique_ptr<Button> _playButton;
	ScoreHandler* _scoreHandler;
	sf::Text _scoreText;
	sf::Font _font;
};

