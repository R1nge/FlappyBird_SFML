#include "pipeEntity.h"
#include "scoreHandler.h"
#include <random>

PipeEntity::PipeEntity(Pipe& pipeTop, Pipe& pipeBottom, sf::Transformable& transform) : _top(pipeTop), _bottom(pipeBottom), _transform(transform)
{
	_top = pipeTop;
	_bottom = pipeBottom;
	_transform = transform;
}

void PipeEntity::move(sf::Vector2f direction, ScoreHandler& scoreHandler)
{
	if (_transform.getPosition().x <= 0) {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 50); // define the range
		std::int32_t g = -distr(gen);
		std::cout << g << std::endl;
		_transform.setPosition(sf::Vector2f(800, g));
		scoreHandler.addScore(1);
	}
	else {
		_transform.move(direction);
	}
	
	_top.collider.update();
	_top.draw(_transform);
	_bottom.collider.update();
	_bottom.draw(_transform);
}