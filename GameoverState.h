#pragma once
#include "state.h"
class GameoverState :
    public State
{
public:
    void Enter() override;
    void Update() override;
    void Exit() override;
};

