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

		float maxHeight = 0;
		float currentHeight = 0;
		for (size_t characterIndex = 0; characterIndex < text.size(); ++characterIndex)
		{
			currentHeight = _font->getGlyph(text[characterIndex], 12, false).bounds.height;
			if (currentHeight > maxHeight)
			{
				maxHeight = currentHeight;
			}
		}

		std::cout << std::endl;
		std::cout << "max height: " << maxHeight << std::endl;
		std::cout << "default height: " << bounds.height << std::endl;

		_text->setOrigin(bounds.width / 2, maxHeight / 2);
		_text->setPosition(size.x / 2, (size.y / 2) - maxHeight * 1.5);
	}
}

Button::~Button()
{
	delete(_font);
	delete(_text);
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
