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

void Pipe::move(sf::Vector2f direction)
{
		shape.move(direction);
}

void Pipe::draw(sf::Transformable& parent)
{
	shape.setFillColor(_originalColor);
	sf::Vector2f position = sf::Vector2f(parent.getPosition().x, shape.getPosition().y + parent.getPosition().y);
	shape.setPosition(position);
	_window->draw(shape);
}