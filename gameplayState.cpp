#include "gameplayState.h"

GameplayState::GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler, Randomizer& randomizer)
{
	_window = &window;
	_scoreHandler = &scoreHandler;
	_randomizer = &randomizer;
}

void GameplayState::Enter()
{
	std::cout << "1" << std::endl;

	bool _drawColliders = false;
	sf::Image playerImage;

	playerImage.loadFromFile("Bird2.png");
	playerImage.createMaskFromColor(sf::Color::Green);

	sf::Texture playerSprite;
	playerSprite.loadFromImage(playerImage);

	Player player(_window, 50, playerSprite);
	PlayerInput playerInput = PlayerInput::PlayerInput(sf::Vector2f(0, 1), 250);

	sf::Texture pipeSprite;
	pipeSprite.loadFromFile("Pipe.png");

	int height = _window->getSize().y * .75f;
	int width = height * 0.1f;

	Pipe pipe(_window, width, height, pipeSprite, sf::Vector2f(-600, 0));
	pipe.shape.setOrigin(sf::Vector2f(pipe.shape.getSize().x / 2, pipe.shape.getSize().y / 2));
	pipe.shape.rotate(180);
	Pipe pipe2(_window, width, height, pipeSprite, sf::Vector2f(-600, 800));
	pipe2.shape.setOrigin(sf::Vector2f(pipe2.shape.getSize().x / 2, pipe2.shape.getSize().y / 2));

	sf::Transformable PipeTransform = sf::Transformable::Transformable();
	PipeEntity pipeEntity = PipeEntity::PipeEntity(pipe, pipe2, PipeTransform, *_randomizer);


	sf::Texture backgroundSprite;
	backgroundSprite.loadFromFile("Background.png");
	sf::RectangleShape backgroundShape = sf::RectangleShape(sf::Vector2f(_window->getSize().x, _window->getSize().y));
	backgroundShape.setTexture(&backgroundSprite);

	if (_font.loadFromFile("Carre.ttf"))
	{
		_scoreText.setFont(_font);
		_scoreText.setCharacterSize(24);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setPosition(sf::Vector2f(_window->getSize().x / 2, _window->getSize().y / 8));
	}
}

void GameplayState::Update() {
	/*playerInput.update();

	player.move(playerInput.getPlayerInput());
	player.collider.Update();

	pipeEntity.move(sf::Vector2f(-1, 0), *_scoreHandler);

	if (player.collider.checkCollision(pipe.collider.Bbox) || player.collider.checkCollision(pipe2.collider.Bbox)) {
		std::cout << "Collision \n" << std::endl;
		std::cout << "exit" << std::endl;
		std::ofstream outFile("score.txt");
		outFile << _scoreHandler->getHighScore();
		outFile.close();
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
	}*/

	_scoreText.setString(std::to_string(_scoreHandler->getScore()));

	_window->draw(_scoreText);

	_window->display();
}

void GameplayState::Exit() {
	
}
