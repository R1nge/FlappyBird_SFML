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

std::istream& operator>>(std::istream& in, ScoreHandler& obj)
{
	in >> obj._score;
	return in;
}

std::ostream& operator<<(std::ostream& out, const ScoreHandler& obj)
{
	out << obj._score << std::endl;
	return out;
}
