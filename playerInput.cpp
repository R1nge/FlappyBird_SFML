#include "playerInput.h"

void PlayerInput::Process()
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

sf::Vector2f PlayerInput::GetPlayerInput()
{
    return _lastPlayerInput;
}
