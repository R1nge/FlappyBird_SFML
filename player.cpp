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
	_lastInput = direction.y;
	shape.move(direction * _speed);
	colliderShape.move(direction * _speed);
	rotate(1);
}

void Player::rotate(int degree) 
{
	std::cout << _lastInput << std::endl;

	// Falling
	if (_lastInput == 1) {
		if (shape.getRotation() < 50 || shape.getRotation() >= 310) {
			shape.rotate(degree);
		}
	}
	// UP JUMP
	else if (_lastInput == -1) {
		if (shape.getRotation() >= 310 || shape.getRotation() <= 50) {
			shape.rotate(-degree * 2);
		}
	}

	if (shape.getRotation() > 50 && shape.getRotation() < 180) 
	{
		shape.setRotation(50);
	} 
	else if (shape.getRotation() < 310 && shape.getRotation() > 180) 
	{
		shape.setRotation(310);
	}
}

void Player::draw()
{
	shape.setFillColor(_originalColor);
	_window->draw(shape);
}