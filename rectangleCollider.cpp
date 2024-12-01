#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

void RectangleCollider::Draw(sf::RectangleShape& shape, sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::Green);
	Bbox = shape.getGlobalBounds();
	window.draw(shape);
}

void RectangleCollider::Update(sf::RectangleShape& shape)
{
	Bbox = shape.getGlobalBounds();
}

bool RectangleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}
