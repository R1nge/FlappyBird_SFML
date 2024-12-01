#pragma once
#include<SFML/Graphics.hpp>

class RectangleCollider
{
public:
	RectangleCollider();
	void Draw(sf::RectangleShape shape, sf::RenderWindow& window);
	bool CheckCollision(sf::RectangleShape shape, sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
};