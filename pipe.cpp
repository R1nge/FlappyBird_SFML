#include "pipe.h"
#include "rectangleCollider.h"

Pipe::Pipe(sf::RenderWindow* window, float width, float height, sf::Color color)
{
	_window = window;
	_width = width;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	collider = RectangleCollider::RectangleCollider();
}

void Pipe::move(sf::Vector2f direction)
{
	if (shape.getPosition().x <= -_width) 
	{
		shape.setPosition(sf::Vector2f(800, shape.getPosition().y));
	}
	else 
	{
		shape.move(direction);
	}
}

void Pipe::draw()
{
	_window->draw(shape);
}
