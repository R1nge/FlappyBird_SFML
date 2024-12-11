#include "pipeEntity.h"
#include "scoreHandler.h"
#include <random>


PipeEntity::PipeEntity(Pipe& pipeTop, Pipe& pipeBottom, sf::Transformable& transform, Randomizer& random) : _top(pipeTop), _bottom(pipeBottom), _transform(transform),  _randomizer(random)
{
	_top = pipeTop;
	_bottom = pipeBottom;
	_transform = transform;
}

void PipeEntity::move(sf::Vector2f direction, ScoreHandler& scoreHandler)
{
	if (_transform.getPosition().x <= 0) {
		int posY = _randomizer.GetRandomNumber();
		_transform.setPosition(sf::Vector2f(800, posY));
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