#pragma once
#include<SFML/Graphics.hpp>

class CircleCollider
{
public:
	CircleCollider();
	void Draw(sf::CircleShape& shape, sf::RenderWindow& window);
	void Update(sf::CircleShape& shape);
	bool CheckCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
};