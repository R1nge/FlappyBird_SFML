#pragma once
#include<SFML/Graphics.hpp>

class CircleCollider
{
public:
	CircleCollider();
	CircleCollider(sf::CircleShape& shape, sf::RenderWindow& window);
	void draw();
	void Update();
	bool checkCollision(sf::FloatRect otherBbox);
	sf::FloatRect Bbox;
private:
	sf::CircleShape* _shape;
	sf::RenderWindow* _window;
};