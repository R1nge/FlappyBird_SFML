#pragma once
#include "state.h"
#include<iostream>
#include"sfml/Graphics.hpp"
#include "player.h"
#include "playerInput.h"
#include "pipe.h"
#include "pipeEntity.h"
#include "StateMachine.h"
#include "GameStatescpp.cpp"

class GameplayState :
    public State
{
public:
    GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler, Randomizer& randomizer, StateMachine& stateMachine);
    void Enter() override;
    void Update() override;
    void Exit() override;
private:
    sf::RenderWindow* _window;
    ScoreHandler* _scoreHandler;
    Randomizer* _randomizer;
    sf::Text _scoreText;
    sf::Font _font;
    Player* _player;
    PlayerInput* _playerInput;
    sf::Texture* _playerSprite;
    sf::Texture* _pipeSprite;
    Pipe* _topPipe;
    Pipe* _bottomPipe;
    sf::Transformable* _pipeTransformable;
    PipeEntity* _pipeEntity;
    sf::Texture* _backgroundSprite;
    sf::RectangleShape* _backgroundShape;
    StateMachine* _stateMachine;
};

