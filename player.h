#pragma once
#include <SFML/Graphics.hpp>
#include "circleCollider.h"

class Player
{
public:
	Player(sf::RenderWindow* window, float raduis, sf::Texture& texture);
	void move(sf::Vector2f direction);
	void rotate(int degree);
	void draw();
	CircleCollider collider;
	sf::CircleShape shape;
	sf::CircleShape colliderShape;
private:
	sf::RenderWindow* _window;
	sf::Color _originalColor;
	float _speed;
	int _lastInput;
};