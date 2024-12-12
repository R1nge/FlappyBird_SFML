#include "Button.h"
#include <iostream>


Button::Button(sf::Vector2f center, sf::Vector2f size)
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
		sf::FloatRect bounds = _text->getLocalBounds();
		sf::Vector2f size(bounds.left * 2 + bounds.width, bounds.top * 2 + bounds.height);
		_text->setPosition(size);
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
