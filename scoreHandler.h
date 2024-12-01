#pragma once
#include <fstream>
#include <iostream>
class ScoreHandler
{
public:
	void addScore(int amount);
	int getScore();
	friend std::istream& operator >> (std::istream& in, ScoreHandler& obj);
	friend std::ostream& operator << (std::ostream& out, const ScoreHandler& obj);
private:
	int _score;
};

