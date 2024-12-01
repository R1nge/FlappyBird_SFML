#pragma once
#include<SFML/Graphics.hpp>
#include "rectangleCollider.h"
#include "scoreHandler.h"

class Pipe
{
public:
	Pipe(sf::RenderWindow* window, float width, float height, sf::Color color);
	void move(sf::Vector2f direction, ScoreHandler& scoreHandler);
	void draw();
	sf::RectangleShape shape;
	RectangleCollider collider;
private:
	sf::RenderWindow* _window;
	sf::Color _originalColor;
	float _width;
};