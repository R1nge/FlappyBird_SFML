#pragma once
#include<SFML/Graphics.hpp>

class RectangleCollider
{
public:
	RectangleCollider();
	void Draw(sf::RectangleShape& shape, sf::RenderWindow& window);
	void Update(sf::RectangleShape& shape);
	bool CheckCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
};