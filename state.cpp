#include "state.h"
#include <iostream>

void State::Enter()
{
	std::cout << "Base state enter" << std::endl;
}

void State::Update()
{
	std::cout << "Base state update" << std::endl;
}

void State::Exit()
{
	std::cout << "Base state exit" << std::endl;
}

void State::Reset() {
	std::cout << "Base state reset" << std::endl;
}
