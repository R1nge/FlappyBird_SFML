#pragma once
#include "state.h"
#include"sfml/Graphics.hpp"
class MenuState : 
	public State
{
public:
	MenuState(sf::RenderWindow& window);
	void Enter() override;
	void Update() override;
	void Exit() override;
private:
	sf::RenderWindow* _window;
	sf::Texture* _backgroundSprite;
	sf::RectangleShape* _backgroundShape;
};

