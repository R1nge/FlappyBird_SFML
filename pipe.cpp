#include "pipe.h"

Pipe::Pipe(sf::RenderWindow* window, float width, float height, sf::Color color)
{
	_window = window;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setFillColor(color);
}

void Pipe::move(sf::Vector2f direction)
{
	shape.move(direction);
}

void Pipe::draw()
{
	_window->draw(shape);
}
