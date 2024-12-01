#include "playerInput.h"

PlayerInput::PlayerInput(sf::Vector2f initialDirection)
{
    _lastPlayerInput = initialDirection;
}

void PlayerInput::process(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        _lastPlayerInput.y = -1;
    }
    else 
    {
        _lastPlayerInput.y = 1;
    }
}

sf::Vector2f PlayerInput::getPlayerInput()
{
    return _lastPlayerInput;
}
