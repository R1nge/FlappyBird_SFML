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
    _canUpdate = false;

    if (_currentState != nullptr) 
    {
        _currentState->Exit();
    }

    _currentState = _states[gameState];
   
    _currentState->Enter();

    _canUpdate = true;
}

void StateMachine::Update()
{
    if (_currentState != nullptr) {
        if (_canUpdate) {
            _currentState->Update();
        }
    }
}
