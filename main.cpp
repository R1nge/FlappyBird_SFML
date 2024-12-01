#include "pipe.h"
#include "player.h"
#include "playerInput.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	bool _drawColliders = false;
	//DONE:
	//Collisions https://www.sfml-dev.org/tutorials/2.6/graphics-transform.php#bounding-boxes
	//TODO:
	//Make two pipes act as one
	//Randomize pipes positions
	//States w state machine; enums based
	//Main menu, in game menu, game over menu
	//Score system, highscore system
	//Sounds
	//Images

	sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");
	window.setFramerateLimit(60);

	Player player(&window, 100, sf::Color::Yellow);
	PlayerInput playerInput = PlayerInput::PlayerInput(sf::Vector2f(0, 1));

	Pipe pipe(&window, 100, 200, sf::Color::Red);
	Pipe pipe2(&window, 100, 200, sf::Color::Red);
	pipe.move(sf::Vector2f(window.getSize().x, 0));
	pipe2.move(sf::Vector2f(window.getSize().x, 600));

	while (window.isOpen())
	{
		player.move(playerInput.GetPlayerInput());
		player.collider.Update();

		pipe.move(sf::Vector2f(-1, 0));
		pipe.collider.Update();

		pipe2.move(sf::Vector2f(-1, 0));
		pipe2.collider.Update();

		if (player.collider.CheckCollision(pipe.collider.Bbox) || player.collider.CheckCollision(pipe2.collider.Bbox)) {
			//std::cout << "Collision with pipe \n";
		}
		else {
			//std::cout << "\n";
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

		if (_drawColliders) 
		{
			player.collider.Draw(window);
			pipe.collider.Draw(window);
			pipe2.collider.Draw(window);
		}
		
		window.display();
	}

	return 0;
}