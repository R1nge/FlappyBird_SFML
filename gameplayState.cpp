#include "gameplayState.h"

GameplayState::GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler)
{
	_window = &window;
	_scoreHandler = &scoreHandler;
}

void GameplayState::Enter()
{
	std::cout << "enter" << std::endl;

	bool _drawColliders = false;
	sf::Texture playerSprite;
	playerSprite.loadFromFile("Bird.png");

	Player player(_window, 100, playerSprite);
	PlayerInput playerInput = PlayerInput::PlayerInput(sf::Vector2f(0, 1), 250);

	sf::Texture pipeSprite;
	pipeSprite.loadFromFile("Pipe.png");

	Pipe pipe(_window, 100, 200, pipeSprite, sf::Vector2f(-600, 0));
	pipe.shape.setOrigin(sf::Vector2f(pipe.shape.getSize().x / 2, pipe.shape.getSize().y / 2));
	pipe.shape.rotate(180);
	Pipe pipe2(_window, 100, 200, pipeSprite, sf::Vector2f(-600, 600));
	pipe2.shape.setOrigin(sf::Vector2f(pipe2.shape.getSize().x / 2, pipe2.shape.getSize().y / 2));

	sf::Transformable PipeTransform = sf::Transformable::Transformable();
	PipeEntity pipeEntity = PipeEntity::PipeEntity(pipe, pipe2, PipeTransform);


	sf::Texture backgroundSprite;
	backgroundSprite.loadFromFile("Background.png");
	sf::RectangleShape backgroundShape = sf::RectangleShape(sf::Vector2f(_window->getSize().x, _window->getSize().y));
	backgroundShape.setTexture(&backgroundSprite);

	sf::Text text;
	sf::Font font;

	if (font.loadFromFile("Carre.ttf"))
	{
		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 8));
	}

	while (_window->isOpen())
	{
		playerInput.update();

		player.move(playerInput.getPlayerInput());
		player.collider.Update();

		pipeEntity.move(sf::Vector2f(-1, 0), *_scoreHandler);

		if (player.collider.checkCollision(pipe.collider.Bbox) || player.collider.checkCollision(pipe2.collider.Bbox)) {
			std::cout << "Collision \n" << std::endl;
			_window->close();
		}

		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();

			playerInput.process(event);

			if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

				_drawColliders = !_drawColliders;
				std::cout << "Collider debug is " << _drawColliders << std::endl;
			}
		}

		_window->clear();

		_window->draw(backgroundShape);

		if (_drawColliders)
		{
			player.collider.draw();
			pipe.collider.draw();
			pipe2.collider.draw();
		}
		else
		{
			player.draw();
			pipe.draw(PipeTransform);
			pipe2.draw(PipeTransform);
		}

		text.setString(std::to_string(_scoreHandler->getHighScore()));

		_window->draw(text);

		//std::cout << scoreHandler.getHighScore() << std::endl;


		//std::ofstream outFile("score.txt");
		//outFile << scoreHandler.getScore();
		//outFile.close();

		//std::ifstream inFile("score.txt");
		//inFile >> scoreHandler;
		//inFile.close();
		//std::cout << scoreHandler.getScore();

		_window->display();
	}
}

void GameplayState::Exit() {
	std::cout << "exit" << std::endl;
}