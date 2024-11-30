#include "player.h"
#include <SFML/Graphics.hpp>
Player::Player(float radius, sf::Color color) {
	shape = sf::CircleShape(radius);
	shape.setFillColor(color);
}