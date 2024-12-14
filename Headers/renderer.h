#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
class Renderer
{
public:
	Renderer(sf::RenderWindow& window);
	void Render(bool debug);
	void Add(Player& circle);
	void Remove(sf::Drawable& drawable);
private:
	sf::RenderWindow* _window;
	std::vector<Player> _entities;
};

