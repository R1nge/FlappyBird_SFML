#pragma once
#include<SFML/Graphics.hpp>

class RectangleCollider
{
public:
	RectangleCollider();
	RectangleCollider(sf::RectangleShape shape);
	void Update();
	void Draw(sf::RenderWindow& window);
	bool CheckCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
private:
	sf::RectangleShape shape;
};