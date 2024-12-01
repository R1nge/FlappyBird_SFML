#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

void CircleCollider::Draw(sf::CircleShape& shape, sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

bool CircleCollider::CheckCollision(sf::CircleShape& circleShape, sf::FloatRect otherBbox)
{
	return circleShape.getGlobalBounds().intersects(otherBbox);
}
