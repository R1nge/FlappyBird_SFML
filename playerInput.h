#pragma once
#include<SFML/Graphics.hpp>

class PlayerInput
{
public:
	PlayerInput(sf::Vector2f initialDirection);
	void Process(sf::Event event);
	sf::Vector2f GetPlayerInput();
private:
	sf::Vector2f _lastPlayerInput;
};