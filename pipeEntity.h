#pragma once
#include "pipe.h"
#include "scoreHandler.h"
class PipeEntity
{
public:
	PipeEntity();
	PipeEntity(Pipe& pipeTop, Pipe& pipeBottom);
	void move(sf::Vector2f direction, ScoreHandler& scoreHandler);
private:
	Pipe* _top;
	Pipe* _bottom;
};

