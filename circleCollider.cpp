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

void CircleCollider::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

bool CircleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}
