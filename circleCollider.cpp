#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

CircleCollider::CircleCollider(sf::CircleShape shape) {
	this->shape = shape;
	Bbox = shape.getGlobalBounds();
}

void CircleCollider::Update()
{
	Bbox = shape.getGlobalBounds();
}

bool CircleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}
