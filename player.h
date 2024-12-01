#pragma once
#include <SFML/Graphics.hpp>
#include "circleCollider.h"

class Player
{
public:
	Player(sf::RenderWindow* window, float raduis, sf::Color color);
	void move(sf::Vector2f direction);
	void draw();
	CircleCollider collider;
	sf::CircleShape shape;
private:
	sf::RenderWindow* _window;
	sf::Color _originalColor;
};