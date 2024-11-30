#pragma once
#include<SFML/Graphics.hpp>

class PlayerInput
{
public:
	void Process();
	sf::Vector2f GetPlayerInput();
private:
	sf::Vector2f _lastPlayerInput;
};