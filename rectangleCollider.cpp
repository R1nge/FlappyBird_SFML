#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

RectangleCollider::RectangleCollider(sf::RectangleShape& shape) 
{
	_shape = &shape;
}

void RectangleCollider::Draw(sf::RenderWindow& window)
{
	_shape->setFillColor(sf::Color::Green);
	Bbox = _shape->getGlobalBounds();
	window.draw(*_shape);
}

void RectangleCollider::Update()
{
	Bbox = _shape->getGlobalBounds();
}

bool RectangleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}