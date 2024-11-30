#pragma once
#include<SFML/Graphics.hpp>
#include "rectangleCollider.h"

class Pipe
{
public:
	Pipe(sf::RenderWindow* window, float width, float height, sf::Color color);
	void move(sf::Vector2f direction);
	void draw();
	sf::RectangleShape shape;
	RectangleCollider collider;
private:
	sf::RenderWindow* _window;
	float _width;
};

