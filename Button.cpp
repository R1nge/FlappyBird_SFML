#include "Button.h"


Button::Button(sf::Vector2f center, sf::Vector2f size)
{
	_rect.setFillColor(sf::Color::Black);
	_rect.setPosition(center - sf::Vector2f(size.x / 2, size.y / 2));
	_rect.setSize(size);
}

bool Button::isPressed(sf::Vector2f mousePosition) {
	return _rect.getGlobalBounds().contains(mousePosition);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(_rect);
}
