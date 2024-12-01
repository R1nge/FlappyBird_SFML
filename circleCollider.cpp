#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

CircleCollider::CircleCollider(sf::CircleShape& shape, sf::RenderWindow& window)
{
	_shape = &shape;
	_window = &window;
}

void CircleCollider::draw()
{
	Bbox = _shape->getGlobalBounds();
	sf::RectangleShape rect = sf::RectangleShape(Bbox.getSize());
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(Bbox.getPosition());
	_window->draw(rect);
}

void CircleCollider::Update()
{
	Bbox = _shape->getGlobalBounds();
}

bool CircleCollider::checkCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}