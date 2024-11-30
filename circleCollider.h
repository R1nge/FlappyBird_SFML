#pragma once
#include<SFML/Graphics.hpp>

class CircleCollider
{
public:
	CircleCollider();
	CircleCollider(sf::CircleShape shape);
	void Update();
	bool CheckCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
private:
	sf::CircleShape shape;
};



