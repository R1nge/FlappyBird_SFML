#include "MenuState.h"
#include "GameStatescpp.cpp"
#include <iostream>

MenuState::MenuState(sf::RenderWindow& window, StateMachine& stateMachine)
{
	_window = &window;
	_stateMachine = &stateMachine;
}

void MenuState::Enter()
{
	_backgroundSprite = new sf::Texture();
	_backgroundSprite->loadFromFile("Background.png");
	_backgroundShape = new sf::RectangleShape(sf::Vector2f(_window->getSize().x, _window->getSize().y));
	_backgroundShape->setTexture(_backgroundSprite);
	_playButton = new Button(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 2), sf::Vector2f(200,100), "Play");
}

void MenuState::Update() {
	_window->clear();

	_window->draw(*_backgroundShape);
	_playButton->draw(*_window);

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
					_stateMachine->SwitchState(game_states::Gameplay);
				}
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			}
		}
	}
}

void MenuState::Exit() {
	delete(_backgroundSprite);
	delete(_backgroundShape);
	delete(_playButton);
}