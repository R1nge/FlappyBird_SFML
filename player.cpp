#include "player.h"
#include "circleCollider.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::RenderWindow* window, float radius, sf::Color color) {
	_window = window;
	shape = sf::CircleShape(radius);
	shape.setFillColor(color);
	shape.setOrigin(sf::Vector2f(radius / 2, radius / 2));
	sf::CircleShape colliderCircle = sf::CircleShape(radius * 2);
	colliderCircle.setFillColor(sf::Color::Green);
	collider = CircleCollider::CircleCollider(colliderCircle);
}

void Player::move(sf::Vector2f direction)
{
	shape.move(direction);
}

void Player::draw()
{
	_window->draw(shape);
}