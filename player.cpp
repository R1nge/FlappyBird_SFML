#include "player.h"
#include "circleCollider.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(sf::RenderWindow* window, float radius, sf::Texture& texture) {
	_window = window;
	shape = sf::CircleShape(radius);
	colliderShape = sf::CircleShape(radius);
	shape.setTexture(&texture);
	_originalColor = shape.getFillColor();
	shape.setOrigin(radius, radius);
	std::cout << std::endl << shape.getOrigin().x << shape.getOrigin().y << std::endl;;
	colliderShape.setOrigin(radius, radius);
	_speed = 3.5f;
	collider = CircleCollider::CircleCollider(colliderShape, *window);
}

void Player::move(sf::Vector2f direction)
{
	shape.move(direction * _speed);
	colliderShape.move(direction * _speed);
}

void Player::rotate(int degree) 
{
	shape.rotate(degree);
}

void Player::draw()
{
	shape.setFillColor(_originalColor);
	_window->draw(shape);
}