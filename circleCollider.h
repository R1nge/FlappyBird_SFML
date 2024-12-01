#pragma once
#include<SFML/Graphics.hpp>

class CircleCollider
{
public:
	CircleCollider();
	void Draw(sf::CircleShape& shape, sf::RenderWindow& window);
	bool CheckCollision(sf::CircleShape& shape, sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
};