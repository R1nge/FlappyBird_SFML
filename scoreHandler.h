#pragma once
#include <fstream>
#include <iostream>
class ScoreHandler
{
public:
	void addScore(int amount);
	int getScore();
	int getHighScore();
	friend std::istream& operator >> (std::istream& in, ScoreHandler& obj);
	friend std::ostream& operator << (std::ostream& out, const ScoreHandler& obj);
private:
	int _score;
	int _highScore;
};

