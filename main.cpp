#include <SFML/Graphics.hpp>
#include "player.h"
#include "playerInput.h"
#include "pipe.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");

    Player player(&window, 100, sf::Color::Yellow);
    PlayerInput playerInput;

    Pipe pipe(&window, 100, 200, sf::Color::Green);
    pipe.move(sf::Vector2f(100,0));

    Pipe pipe2(&window, 100, 200, sf::Color::Green);
    pipe2.move(sf::Vector2f(100, 400));

    float fps = 60;
    float frameTime = static_cast<float>(1) / fps;
    sf::Clock frameClock;
    while (window.isOpen())
    {
        if (frameClock.getElapsedTime().asMilliseconds() >= frameTime) {
            frameClock.restart();
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
        pipe.draw();
        pipe2.draw();
        window.display();
    }

    return 0;
}