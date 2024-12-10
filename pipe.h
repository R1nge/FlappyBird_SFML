#pragma once
#include<SFML/Graphics.hpp>
#include "rectangleCollider.h"
#include "scoreHandler.h"

class Pipe
{
public:
	Pipe();
	Pipe(sf::RenderWindow* window, float width, float height, sf::Texture& sprite, sf::Vector2f startPosition);
	void move(sf::Vector2f direction);
	void draw(sf::Transformable& parent);
	sf::RectangleShape shape;
	RectangleCollider collider;
private:
	sf::RenderWindow* _window;
	sf::Color _originalColor;
	float _width;
	sf::Vector2f _startPosition;
};