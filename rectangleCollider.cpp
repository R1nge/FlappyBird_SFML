#include "rectangleCollider.h"
#include<SFML/Graphics.hpp>

RectangleCollider::RectangleCollider() = default;

RectangleCollider::RectangleCollider(sf::RectangleShape& shape, sf::RenderWindow& window) 
{
	_shape = &shape;
	_window = &window;
}

void RectangleCollider::draw()
{
	Bbox = _shape->getGlobalBounds();
	sf::RectangleShape rect = sf::RectangleShape(Bbox.getSize());
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(Bbox.getPosition());
	_window->draw(rect);
}

void RectangleCollider::update()
{
	Bbox = _shape->getGlobalBounds();
}

bool RectangleCollider::checkCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}