#include "StateMachine.h"

void StateMachine::AddState(State* state, game_states gameState)
{
    _states[gameState] = state;
}

void StateMachine::RemoveState(game_states gameState)
{
    _states.erase(gameState);
}

void StateMachine::SwitchState(game_states gameState)
{
    //_currentState.Exit();
    _currentState = _states[gameState];
    _currentState->Enter();
}
