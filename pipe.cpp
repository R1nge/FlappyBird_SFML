#include "pipe.h"
#include "scoreHandler.h"
#include "rectangleCollider.h"

Pipe::Pipe() = default;

Pipe::Pipe(sf::RenderWindow* window, float width, float height, sf::Texture& sprite)
{
	_window = window;
	_width = width;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	_originalColor = shape.getFillColor();;
	shape.setTexture(&sprite);;
	collider = RectangleCollider::RectangleCollider(shape, *window);
}

void Pipe::move(sf::Vector2f direction, ScoreHandler& scoreHandler)
{
	if (shape.getPosition().x <= -_width) 
	{
		shape.setPosition(sf::Vector2f(800, shape.getPosition().y));
		scoreHandler.addScore(1);
	}
	else 
	{
		shape.move(direction);
	}
}

void Pipe::draw()
{
	shape.setFillColor(_originalColor);
	_window->draw(shape);
}