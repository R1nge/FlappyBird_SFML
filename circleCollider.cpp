#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

CircleCollider::CircleCollider(sf::CircleShape& shape)
{
	_shape = &shape;
}

void CircleCollider::Draw(sf::RenderWindow& window)
{
	_shape->setFillColor(sf::Color::Green);
	Bbox = _shape->getGlobalBounds();
	window.draw(*_shape);
}

void CircleCollider::Update()
{
	Bbox = _shape->getGlobalBounds();
}

bool CircleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}