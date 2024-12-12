#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow& window)
{
	_window = &window;
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
	}


	_window->clear();

	_window->draw(*_backgroundShape);

	_window->display();
}

void MenuState::Exit() {

}