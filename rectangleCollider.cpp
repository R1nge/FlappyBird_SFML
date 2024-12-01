#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

void RectangleCollider::Draw(sf::RectangleShape shape, sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::Green);
	Bbox = shape.getGlobalBounds();
	window.draw(shape);
}

bool RectangleCollider::CheckCollision(sf::RectangleShape shape, sf::FloatRect otherBbox)
{
	return shape.getGlobalBounds().intersects(otherBbox);
}
