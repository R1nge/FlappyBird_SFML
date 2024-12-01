#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

RectangleCollider::RectangleCollider(sf::RectangleShape shape) {
	this->shape = shape;
	Bbox = shape.getLocalBounds();
}

void RectangleCollider::Update()
{
	Bbox = shape.getLocalBounds();
}

void RectangleCollider::Draw(sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

bool RectangleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	Bbox = shape.getLocalBounds();
	return Bbox.intersects(otherBbox);
}
