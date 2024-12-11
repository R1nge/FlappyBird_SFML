#pragma once
#include "pipe.h"
#include "scoreHandler.h"
#include "Randomizer.h"
class PipeEntity
{
public:
	PipeEntity(Pipe& pipeTop, Pipe& pipeBottom, sf::Transformable& transform, Randomizer& randomizer);
	void move(sf::Vector2f direction, ScoreHandler& scoreHandler);
private:
	Pipe& _top;
	Pipe& _bottom;
	sf::Transformable& _transform;
	Randomizer& _randomizer;
};