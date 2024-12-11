#pragma once
#include "state.h"
#include<iostream>
#include"sfml/Graphics.hpp"
#include "player.h"
#include "playerInput.h"
#include "pipe.h"
#include "pipeEntity.h"
class GameplayState :
    public State
{
public:
    GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler);
    void Enter();
    void Exit();
private:
    sf::RenderWindow* _window;
    ScoreHandler* _scoreHandler;
};

