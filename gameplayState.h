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
    GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler, Randomizer& randomizer);
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
};

