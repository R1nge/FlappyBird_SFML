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
	rotate(5);
}

void Player::rotate(int degree) 
{
	std::cout << _lastInput << std::endl;
	int minDegree = 30;
	int maxDegree = 330;

	// Falling
	if (_lastInput == 1) 
	{
		if (shape.getRotation() < minDegree || shape.getRotation() >= maxDegree) 
		{
			shape.rotate(degree);
		}
	}
	// UP JUMP
	else if (_lastInput == -1) 
	{
		if (shape.getRotation() >= maxDegree || shape.getRotation() <= minDegree) 
		{
			shape.rotate(-degree);
		}
	}

	if (shape.getRotation() > minDegree && shape.getRotation() < 180) 
	{
		shape.setRotation(minDegree);
	} 
	else if (shape.getRotation() < maxDegree && shape.getRotation() > 180) 
	{
		shape.setRotation(maxDegree);
	}
}

void Player::draw()
{
	shape.setFillColor(_originalColor);
	_window->draw(shape);
}