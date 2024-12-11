#include "scoreHandler.h"
#include <assert.h>

void ScoreHandler::addScore(int amount)
{
	assert(("Score to add must be > 0", amount > 0));
	_score += amount;

	if (_score > _highScore) {
		_highScore = _score;
	}
}

int ScoreHandler::getScore() 
{
	return _score;
}

int ScoreHandler::getHighScore()
{
	return _highScore;
}

std::istream& operator>>(std::istream& in, ScoreHandler& obj)
{
	in >> obj._highScore;
	return in;
}

std::ostream& operator<<(std::ostream& out, const ScoreHandler& obj)
{
	out << obj._highScore << std::endl;
	return out;
}
