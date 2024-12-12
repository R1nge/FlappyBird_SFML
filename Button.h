#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
class Button
{
public:
	Button(sf::Vector2f center, sf::Vector2f size);
	bool isPressed(sf::Vector2f mousePosition);
	void draw(sf::RenderWindow& renderWindow);
	void setText(std::string text);
private:
	sf::RectangleShape _rect;
	sf::Text* _text;
	sf::Font* _font;
};

