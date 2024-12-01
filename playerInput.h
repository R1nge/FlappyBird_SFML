#pragma once
#include<SFML/Graphics.hpp>

class PlayerInput
{
public:
	PlayerInput(sf::Vector2f initialDirection, float cooldown);
	void process(sf::Event event);
	void update();
	sf::Vector2f getPlayerInput();
private:
	sf::Vector2f _lastPlayerInput;
	sf::Clock _inputCooldown;
	float _cooldown;
	bool _canSendInput;
};