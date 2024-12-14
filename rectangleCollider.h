#pragma once
#include<SFML/Graphics.hpp>

class RectangleCollider
{
public:
	RectangleCollider();
	RectangleCollider(sf::RectangleShape& shape, sf::RenderWindow& window);
	void draw();
	void update();
	bool checkCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
private:
	sf::RectangleShape* _shape;
	sf::RenderWindow* _window;
};