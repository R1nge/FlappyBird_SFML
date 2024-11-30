#include "player.h"
#include <SFML/Graphics.hpp>

Player::Player(sf::RenderWindow* window, float radius, sf::Color color) {
	_window = window;
	shape = sf::CircleShape(radius);
	shape.setFillColor(color);
}

void Player::move(sf::Vector2f direction)
{
	shape.move(direction);
}

void Player::draw()
{
	_window->draw(shape);
}
