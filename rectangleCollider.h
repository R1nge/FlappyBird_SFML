#pragma once
#include<SFML/Graphics.hpp>

class RectangleCollider
{
public:
	RectangleCollider();
	RectangleCollider(sf::RectangleShape& shape);
	void Draw(sf::RenderWindow& window);
	void Update();
	bool CheckCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
private:
	sf::RectangleShape* _shape;
};