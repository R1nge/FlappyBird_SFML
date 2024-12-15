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
    std::unique_ptr<Player> _player;
    std::unique_ptr<PlayerInput> _playerInput;
    std::unique_ptr<sf::Texture> _playerSprite;
    std::unique_ptr<sf::Texture> _pipeSprite;
    std::unique_ptr<Pipe> _topPipe;
    std::unique_ptr<Pipe> _bottomPipe;
    std::unique_ptr<sf::Transformable> _pipeTransformable;
    std::unique_ptr<PipeEntity> _pipeEntity;
    std::unique_ptr<sf::Texture> _backgroundSprite;
    std::unique_ptr<sf::RectangleShape> _backgroundShape;
    StateMachine* _stateMachine;
    bool _drawColliders;
};

