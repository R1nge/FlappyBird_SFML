#include "player.h"
#include "circleCollider.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::RenderWindow* window, float radius, sf::Color color) {
	_window = window;
	shape = sf::CircleShape(radius);
	shape.setFillColor(color);
	_originalColor = color;
	//shape.setOrigin(sf::Vector2f(radius / 2, radius / 2));
	collider = CircleCollider::CircleCollider(shape);
}

void Player::move(sf::Vector2f direction)
{
	shape.move(direction);
}

void Player::draw()
{
	shape.setFillColor(_originalColor);
	_window->draw(shape);
}