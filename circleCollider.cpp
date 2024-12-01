#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

void CircleCollider::Draw(sf::CircleShape& shape, sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::Green);
	Bbox = shape.getGlobalBounds();
	window.draw(shape);
}

void CircleCollider::Update(sf::CircleShape& shape)
{
	Bbox = shape.getGlobalBounds();
}

bool CircleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}