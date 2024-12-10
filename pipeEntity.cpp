#include "pipeEntity.h"
#include "scoreHandler.h"

PipeEntity::PipeEntity(Pipe& pipeTop, Pipe& pipeBottom, sf::Transformable& transform) : _top(pipeTop), _bottom(pipeBottom), _transform(transform)
{
	_top = pipeTop;
	_bottom = pipeBottom;
	_transform = transform;
}

void PipeEntity::move(sf::Vector2f direction, ScoreHandler& scoreHandler)
{
	if (_transform.getPosition().x <= 0) {
		_transform.setPosition(sf::Vector2f(800, 0));
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