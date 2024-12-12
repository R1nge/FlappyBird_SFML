#include "MenuState.h"
#include "GameStatescpp.cpp"

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
}

void MenuState::Update() {
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				_stateMachine->SwitchState(game_states::Gameplay);
			}
		}
	}


	_window->clear();

	_window->draw(*_backgroundShape);

	_window->display();
}

void MenuState::Exit() {

}