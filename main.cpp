#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    float fps = 60;
    float frameTime = static_cast<float>(1) / fps;
    sf::Clock frame_clock;
    sf::Vector2f direction;
    while (window.isOpen())
    {
        if (frame_clock.getElapsedTime().asMilliseconds() >= frameTime) {
            frame_clock.restart();
            shape.move(direction);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                direction.y = -1;
            }
            else {
                direction.y = 1;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}