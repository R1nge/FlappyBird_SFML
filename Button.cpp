#include "Button.h"
#include <iostream>


Button::Button(sf::Vector2f center, sf::Vector2f size, std::string text)
{
	_rect.setFillColor(sf::Color::Black);
	sf::Vector2f adjustedCenter = center - sf::Vector2f(size.x / 2, size.y / 2);
	_rect.setPosition(adjustedCenter);
	_rect.setSize(size);
	_font = new sf::Font();
	if (_font->loadFromFile("RobotoMono-Regular.ttf")) 
	{
		_text = new sf::Text();
		_text->setFont(*_font);
		_text->setFillColor(sf::Color::White);
		_text->setString(text);
		sf::FloatRect bounds = _text->getLocalBounds();
		std::cout << "X: " << size.x << " " << "Y: " << size.y << std::endl;
		_text->setOrigin(bounds.width / 2, bounds.height / 2);
		_text->setPosition(size.x / 2, size.y / 2);
	}
}

bool Button::isPressed(sf::Vector2f mousePosition) {
	return _rect.getGlobalBounds().contains(mousePosition);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(_rect);
	window.draw(*_text, _rect.getTransform());
}

void Button::setText(std::string text)
{
	_text->setString(text);
}
