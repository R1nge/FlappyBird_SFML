#pragma once
#include <random>
class Randomizer
{
public:
	Randomizer(int rangeMin, int rangeMax);
	int GetRandomNumber();
private:
	std::mt19937 _gen;
	std::uniform_int_distribution<> _dist;
};

