#include "rectangleCollider.h"

RectangleCollider::RectangleCollider() = default;

RectangleCollider::RectangleCollider(sf::RectangleShape shape) {
	this->shape = shape;
	Bbox = shape.getGlobalBounds();
}

void RectangleCollider::Update()
{
	Bbox = shape.getGlobalBounds();
}

bool RectangleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	Bbox = shape.getGlobalBounds();
	return Bbox.intersects(otherBbox);
}
