#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

RectangleCollider::RectangleCollider(sf::RectangleShape& shape, sf::RenderWindow& window) 
{
	_shape = &shape;
	_window = &window;
}

void RectangleCollider::draw()
{
	_shape->setFillColor(sf::Color::Green);
	Bbox = _shape->getGlobalBounds();
	_window->draw(*_shape);
}

void RectangleCollider::update()
{
	Bbox = _shape->getGlobalBounds();
}

bool RectangleCollider::checkCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}