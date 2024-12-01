#include "pipe.h"
#include "player.h"
#include "playerInput.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	//TODO:
	//Collisions https://www.sfml-dev.org/tutorials/2.6/graphics-transform.php#bounding-boxes
	//States w state machine; enums based
	//Main menu, in game menu, game over menu
	//Score system, highscore system
	//Sounds
	//Images

	sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");
	window.setFramerateLimit(60);

	Player player(&window, 100, sf::Color::Yellow);
	PlayerInput playerInput;

	Pipe pipe(&window, 100, 200, sf::Color::Red);
	Pipe pipe2(&window, 100, 200, sf::Color::Red);
	pipe2.move(sf::Vector2f(0, 600));

	while (window.isOpen())
	{
		player.move(playerInput.GetPlayerInput());
		pipe.move(sf::Vector2f(-1, 0));
		pipe2.move(sf::Vector2f(-1, 0));

		player.collider.Update();
		pipe.collider.Update();
		pipe2.collider.Update();

		if (player.collider.CheckCollision(pipe.collider.Bbox)) {
			std::cout << "Collision with pipe \n";
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			playerInput.Process();
		}

		window.clear();
		player.collider.Draw(window);
		pipe.collider.Draw(window);
		pipe2.collider.Draw(window);
		player.draw();
		pipe.draw();
		pipe2.draw();
		window.display();
	}

	return 0;
}