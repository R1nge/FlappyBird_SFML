#pragma once
#include<SFML/Graphics.hpp>

class PlayerInput
{
public:
	PlayerInput(sf::Vector2f initialDirection);
	void process(sf::Event event);
	sf::Vector2f getPlayerInput();
private:
	sf::Vector2f _lastPlayerInput;
};