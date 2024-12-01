#include "pipe.h"
#include "player.h"
#include "playerInput.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	bool _drawColliders = false;

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
		player.move(playerInput.getPlayerInput());
		player.collider.Update();

		pipe.move(sf::Vector2f(-1, 0));
		pipe.collider.update();

		pipe2.move(sf::Vector2f(-1, 0));
		pipe2.collider.update();

		if (player.collider.checkCollision(pipe.collider.Bbox) || player.collider.checkCollision(pipe2.collider.Bbox)) {
			std::cout << "Collision with pipe \n";
		}
		else {
			//std::cout << "\n";
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			playerInput.process(event);

			if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				
				_drawColliders = !_drawColliders;
				std::cout << "Collider debug is " << _drawColliders << std::endl;
			}
		}

		window.clear();

		if (_drawColliders) 
		{
			player.collider.draw();
			pipe.collider.draw();
			pipe2.collider.draw();
		}
		else 
		{
			player.draw();
			pipe.draw();
			pipe2.draw();
		}
		
		window.display();
	}

	return 0;
}