#include "player.h"
#include "circleCollider.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::RenderWindow* window, float radius, sf::Texture& texture) {
	_window = window;
	shape = sf::CircleShape(radius);
	shape.setTexture(&texture);
	_originalColor = shape.getFillColor();
	//shape.setOrigin(sf::Vector2f(radius / 2, radius / 2));
	collider = CircleCollider::CircleCollider(shape, *window);
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