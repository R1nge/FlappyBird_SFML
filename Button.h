#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Button
{
public:
	Button(sf::Vector2f center, sf::Vector2f size);
	bool isPressed(sf::Vector2f mousePosition);
	void draw(sf::RenderWindow& renderWindow);
private:
	sf::RectangleShape _rect;
};

