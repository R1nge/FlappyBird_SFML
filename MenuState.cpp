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
	_entering = false;
}

void MenuState::Update() {
	if (_entering || _exiting)
	{
		return;
	}

	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (event.mouseButton.x >= 100) {
					_stateMachine->SwitchState(game_states::Gameplay);
				}
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			}
		}
	}


	_window->clear();

	_window->draw(*_backgroundShape);

	_window->display();
}

void MenuState::Exit() {
	_exiting = true;
	delete(_backgroundSprite);
	delete(_backgroundShape);
	_exiting = false;
}