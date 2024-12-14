#include "playerInput.h"

PlayerInput::PlayerInput(sf::Vector2f initialDirection, float cooldown)
{
    _lastPlayerInput = initialDirection;
    _inputCooldown = sf::Clock();
    _cooldown = cooldown;
}

void PlayerInput::process(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space) 
        {
            if (_canSendInput) 
            {
                _inputCooldown.restart();
                _lastPlayerInput.y = -1;
                _canSendInput = false;
            }
        }
    }
}

void PlayerInput::update() {
    if (_inputCooldown.getElapsedTime().asMilliseconds() >= _cooldown)
    {
        _lastPlayerInput.y = 1;
        _canSendInput = true;
    }
}

sf::Vector2f PlayerInput::getPlayerInput()
{
    return _lastPlayerInput;
}
