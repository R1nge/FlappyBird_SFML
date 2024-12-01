#include "pipe.h"
#include "player.h"
#include "playerInput.h"
#include"scoreHandler.h"
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
	//Sounds
	//Images

	ScoreHandler scoreHandler = ScoreHandler();

	sf::RenderWindow window(sf::VideoMode(720, 1280), "Flappy Bird");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	sf::Texture playerSprite;
	playerSprite.loadFromFile("Bird.png");

	Player player(&window, 100, playerSprite);
	PlayerInput playerInput = PlayerInput::PlayerInput(sf::Vector2f(0, 1), 250);
	
	sf::Texture pipeSprite;
	pipeSprite.loadFromFile("Pipe.png");

	Pipe pipe(&window, 100, 200, pipeSprite);
	pipe.shape.setOrigin(sf::Vector2f(pipe.shape.getSize().x / 2, pipe.shape.getSize().y / 2));
	pipe.shape.rotate(180);
	Pipe pipe2(&window, 100, 200, pipeSprite);
	pipe2.shape.setOrigin(sf::Vector2f(pipe2.shape.getSize().x / 2, pipe2.shape.getSize().y / 2));
	pipe.move(sf::Vector2f(window.getSize().x, 0), scoreHandler);
	pipe2.move(sf::Vector2f(window.getSize().x, 600), scoreHandler);

	sf::Text text;
	sf::Font font;

	if (font.loadFromFile("Carre.ttf"))
	{
		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 8));
	}

	while (window.isOpen())
	{
		playerInput.update();

		player.move(playerInput.getPlayerInput());
		player.collider.Update();

		pipe.move(sf::Vector2f(-1, 0), scoreHandler);
		pipe.collider.update();

		pipe2.move(sf::Vector2f(-1, 0), scoreHandler);
		pipe2.collider.update();

		if (player.collider.checkCollision(pipe.collider.Bbox) || player.collider.checkCollision(pipe2.collider.Bbox)) {
			std::cout << "Collision \n" << std::endl;
		}
		else {
			
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

		text.setString(std::to_string(scoreHandler.getHighScore()));

		window.draw(text);

		//std::cout << scoreHandler.getHighScore() << std::endl;


		//std::ofstream outFile("score.txt");
		//outFile << scoreHandler.getScore();
		//outFile.close();

		//std::ifstream inFile("score.txt");
		//inFile >> scoreHandler;
		//inFile.close();
		//std::cout << scoreHandler.getScore();
		
		window.display();
	}

	return 0;
}