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
	sf::RectangleShape rect = sf::RectangleShape(_shape->getGlobalBounds().getSize());
	rect.setFillColor(sf::Color::Green);
	//rect.setOrigin(sf::Vector2f(rect.getPosition().x / 2, rect.getPosition().y / 2));
	rect.setPosition(_shape->getPosition());
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