#include "renderer.h"
#include "player.h"
#include <SFML/Graphics.hpp>

Renderer::Renderer(sf::RenderWindow& window)
{
	_window = &window;
}

void Renderer::Render(bool debug)
{
	if (debug) {

	}
	else {
		for (auto& const entity : _entities)
		{
			entity.draw();
		}
	}
}

void Renderer::Add(Player& target)
{
	_entities.push_back(target);
}
