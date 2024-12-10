#include "pipe.h"
#include "scoreHandler.h"
#include "rectangleCollider.h"

Pipe::Pipe() = default;

Pipe::Pipe(sf::RenderWindow* window, float width, float height, sf::Texture& sprite, sf::Vector2f startPosition)
{
	_window = window;
	_width = width;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	_originalColor = shape.getFillColor();;
	shape.setTexture(&sprite);;
	collider = RectangleCollider::RectangleCollider(shape, *window);
	shape.setPosition(startPosition);
	_startPosition = startPosition;
}

void Pipe::move(sf::Vector2f direction)
{
	shape.move(direction);
}

void Pipe::draw(sf::Transformable& parent)
{
	shape.setFillColor(_originalColor);
	sf::Vector2f position = sf::Vector2f(parent.getPosition().x, _startPosition.y + parent.getPosition().y);
	shape.setPosition(position);
	_window->draw(shape);
}