#include "Randomizer.h"
Randomizer::Randomizer(int rangeMin, int rangeMax)
{
	std::random_device rd;
	_gen = std::mt19937();
	_dist = std::uniform_int_distribution<>(rangeMin, rangeMax);
	
}

int Randomizer::GetRandomNumber()
{
	return -_dist(_gen);;
}
