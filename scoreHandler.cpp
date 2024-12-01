#include "scoreHandler.h"
#include <assert.h>

void ScoreHandler::addScore(int amount)
{
	assert(("Score to add must be > 0", amount > 0));
	_score += amount;
}

int ScoreHandler::getScore()
{
	return _score;
}
