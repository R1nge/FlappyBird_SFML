#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::RenderWindow* window, float raduis, sf::Color color);
	void move(sf::Vector2f direction);
	void draw();
	sf::CircleShape shape;
private:
	sf::RenderWindow* _window;
};

