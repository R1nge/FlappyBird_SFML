#pragma once
#include <map>

#include "state.h"
enum class game_states;

class StateMachine
{
public:
	void AddState(State* state, game_states gameState);
	void RemoveState(game_states gameState);
	void SwitchState(game_states);
	void Update();
private:
	std::map<game_states, State*> _states;
	State* _currentState;
};

