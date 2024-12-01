#include "pipeEntity.h"
#include "scoreHandler.h"

PipeEntity::PipeEntity() = default;

PipeEntity::PipeEntity(Pipe& pipeTop, Pipe& pipeBottom)
{
	_top = &pipeTop;
	_bottom = &pipeBottom;
}

void PipeEntity::move(sf::Vector2f direction, ScoreHandler& scoreHandler)
{
	_top->move(direction, scoreHandler);
	_top->collider.update();
	_bottom->move(direction, scoreHandler);
	_bottom->collider.update();
}