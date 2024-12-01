#include "circleCollider.h"

CircleCollider::CircleCollider() = default;

CircleCollider::CircleCollider(sf::CircleShape& shape)
{
	_shape = &shape;
}

void CircleCollider::Draw(sf::RenderWindow& window)
{
	Bbox = _shape->getGlobalBounds();
	sf::RectangleShape rect = sf::RectangleShape(_shape->getGlobalBounds().getSize());
	rect.setFillColor(sf::Color::Green);
	//rect.setOrigin(sf::Vector2f(rect.getPosition().x / 2, rect.getPosition().y / 2));
	rect.setPosition(_shape->getPosition());
	window.draw(rect);
}

void CircleCollider::Update()
{
	Bbox = _shape->getGlobalBounds();
}

bool CircleCollider::CheckCollision(sf::FloatRect otherBbox)
{
	return Bbox.intersects(otherBbox);
}