#include <SFML/Graphics.hpp>
#include "player.h"
#include "playerInput.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");
    Player player(&window, 100, sf::Color::Green);
    PlayerInput playerInput;
    float fps = 60;
    float frameTime = static_cast<float>(1) / fps;
    sf::Clock frame_clock;
    while (window.isOpen())
    {
        if (frame_clock.getElapsedTime().asMilliseconds() >= frameTime) {
            frame_clock.restart();
            player.move(playerInput.GetPlayerInput());
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            playerInput.Process();
        }

        window.clear();
        player.draw();
        window.display();
    }

    return 0;
}