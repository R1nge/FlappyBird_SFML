#include "GameoverState.h"
#include "GameStatescpp.cpp"
#include <iostream>


GameoverState::GameoverState(sf::RenderWindow& window, StateMachine& stateMachine, ScoreHandler& scoreHandler)
{
	_window = &window;
	_stateMachine = &stateMachine;
	_scoreHandler = &scoreHandler;
}

void GameoverState::Enter()
{
	_backgroundSprite = std::make_unique<sf::Texture>();;
	_backgroundSprite->loadFromFile("Background.png");
	_backgroundShape = std::make_unique<sf::RectangleShape>(sf::Vector2f(_window->getSize().x, _window->getSize().y));
	_backgroundShape->setTexture(_backgroundSprite.get());
	_playButton = std::make_unique<Button>(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 2), sf::Vector2f(200, 100), "Retry");

	//TODO: new font with chars
	if (_font.loadFromFile("Carre.ttf"))
	{
		_scoreText.setFont(_font);
		_scoreText.setCharacterSize(24);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setPosition(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 8));
	}

	_scoreText.setString(std::to_string(_scoreHandler->getHighScore()));
}

void GameoverState::Update() 
{
	_window->clear();

	_window->draw(*_backgroundShape);
	_playButton->draw(*_window);
	_window->draw(_scoreText);

	_window->display();

	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (_playButton->isPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					_stateMachine->SwitchState(game_states::Menu);
				}
			}
		}
	}
}

void GameoverState::Exit() 
{
	_backgroundSprite.reset();
	_backgroundShape.reset();
	_playButton.reset();
	_scoreHandler->reset();
	std::cout << "Exit game over" << std::endl;
}
