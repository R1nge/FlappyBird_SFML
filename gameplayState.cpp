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

	_playerSprite = new sf::Texture();
	_playerSprite->loadFromImage(playerImage);

	_player = new Player(_window, 50, *_playerSprite);
	_playerInput = new PlayerInput(sf::Vector2f(0, 1), 250);

	_pipeSprite = new sf::Texture();
	_pipeSprite->loadFromFile("Pipe.png");

	int height = _window->getSize().y * .75f;
	int width = height * 0.1f;

	_topPipe = new Pipe(_window, width, height, *_pipeSprite, sf::Vector2f(-600, 0));
	_topPipe->shape.setOrigin(sf::Vector2f(_topPipe->shape.getSize().x / 2, _topPipe->shape.getSize().y / 2));
	_topPipe->shape.rotate(180);
	_bottomPipe = new Pipe(_window, width, height, *_pipeSprite, sf::Vector2f(-600, 800));
	_bottomPipe->shape.setOrigin(sf::Vector2f(_bottomPipe->shape.getSize().x / 2, _bottomPipe->shape.getSize().y / 2));

	_pipeTransformable = new sf::Transformable();
	_pipeEntity = new PipeEntity(*_topPipe, *_bottomPipe, *_pipeTransformable, *_randomizer);

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
	_playerInput->update();

	std::cout << _playerInput->getPlayerInput().y << std::endl;

	_player->move(_playerInput->getPlayerInput());
	_player->collider.Update();

	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();

		_playerInput->process(event);

		if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			//_drawColliders = !_drawColliders;
			//std::cout << "Collider debug is " << _drawColliders << std::endl;
		}
	}
	
	_pipeEntity->move(sf::Vector2f(-1, 0), *_scoreHandler);

	if (_player->collider.checkCollision(_topPipe->collider.Bbox) || _player->collider.checkCollision(_bottomPipe->collider.Bbox)) {
		std::cout << "Collision \n" << std::endl;
		std::cout << "exit" << std::endl;
		std::ofstream outFile("score.txt");
		outFile << _scoreHandler->getHighScore();
		outFile.close();
		_window->close();
	}

	_window->clear();

	/*_window->draw(backgroundShape);

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

	_window->clear();

	_player->draw();
	_topPipe->draw(*_pipeTransformable);
	_bottomPipe->draw(*_pipeTransformable);

	_scoreText.setString(std::to_string(_scoreHandler->getScore()));

	_window->draw(_scoreText);

	_window->display();
}

void GameplayState::Exit() {
	delete(_playerInput);
	delete(_player);
	delete(_playerSprite);
	delete(_pipeSprite);
	delete(_pipeEntity);
	delete(_pipeTransformable);
	delete(_bottomPipe);
	delete(_topPipe);
}
