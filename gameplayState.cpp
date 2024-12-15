#include "gameplayState.h"


GameplayState::GameplayState(sf::RenderWindow& window, ScoreHandler& scoreHandler, Randomizer& randomizer, StateMachine& stateMachine)
{
	_window = &window;
	_scoreHandler = &scoreHandler;
	_randomizer = &randomizer;
	_stateMachine = &stateMachine;
}

void GameplayState::Enter()
{
	std::cout << "1" << std::endl;

	bool _drawColliders = false;
	sf::Image playerImage;

	playerImage.loadFromFile("Bird2.png");
	playerImage.createMaskFromColor(sf::Color::Green);

	_playerSprite = std::make_unique<sf::Texture>();
	_playerSprite->loadFromImage(playerImage);

	_player = std::make_unique<Player>(_window, 50, *_playerSprite);
	_player->move(sf::Vector2f(20, 0));
	_playerInput = std::make_unique<PlayerInput>(sf::Vector2f(0, 1), 250);

	sf::Image pipeImage;
	pipeImage.loadFromFile("Pipe.png");
	pipeImage.createMaskFromColor(sf::Color::White);

	_pipeSprite = std::make_unique<sf::Texture>();
	_pipeSprite->loadFromImage(pipeImage);

	int height = _window->getSize().y * .75f;
	int width = height * 0.1f;

	_topPipe = std::make_unique<Pipe>(_window, width, height, *_pipeSprite, sf::Vector2f(-600, 0));
	_topPipe->shape.setOrigin(sf::Vector2f(_topPipe->shape.getSize().x / 2, _topPipe->shape.getSize().y / 2));
	_topPipe->shape.rotate(180);
	_bottomPipe = std::make_unique<Pipe>(_window, width, height, *_pipeSprite, sf::Vector2f(-600, 800));
	_bottomPipe->shape.setOrigin(sf::Vector2f(_bottomPipe->shape.getSize().x / 2, _bottomPipe->shape.getSize().y / 2));

	_pipeTransformable = std::make_unique<sf::Transformable>();
	_pipeTransformable->setPosition(600, 0);
	_pipeEntity = std::make_unique<PipeEntity>(*_topPipe, *_bottomPipe, *_pipeTransformable, *_randomizer);

	_backgroundSprite = std::make_unique<sf::Texture>();
	_backgroundSprite->loadFromFile("Background.png");
	_backgroundShape = std::make_unique<sf::RectangleShape>(sf::Vector2f(_window->getSize().x, _window->getSize().y));
	_backgroundShape->setTexture(_backgroundSprite.get());

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

	_player->move(_playerInput->getPlayerInput());
	_player->collider.Update();

	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();

		_playerInput->process(event);

		if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			_drawColliders = !_drawColliders;
			std::cout << "Collider debug is " << _drawColliders << std::endl;
		}
	}
	
	_pipeEntity->move(sf::Vector2f(-1, 0), *_scoreHandler);

	_window->clear();

	_window->draw(*_backgroundShape);

	if (_drawColliders) 
	{
		_player->collider.draw();
		_topPipe->collider.draw();
		_bottomPipe->collider.draw();
	}
	else 
	{
		_player->draw();
		_topPipe->draw(*_pipeTransformable);
		_bottomPipe->draw(*_pipeTransformable);
	}

	_scoreText.setString(std::to_string(_scoreHandler->getScore()));

	_window->draw(_scoreText);

	_window->display();


	if (_player->collider.checkCollision(_topPipe->collider.Bbox) || _player->collider.checkCollision(_bottomPipe->collider.Bbox)) {
		_stateMachine->SwitchState(game_states::Gameover);
	}
}

void GameplayState::Exit() {
	_playerInput.reset();
	_player.reset();
	_playerSprite.reset();
	_pipeSprite.reset();
	_pipeEntity.reset();
	_pipeTransformable.reset();
	_bottomPipe.reset();
	_topPipe.reset();
	_backgroundSprite.reset();
	_backgroundShape.reset();
	_drawColliders = false;

	std::ofstream outFile("score.txt");
	outFile << _scoreHandler->getHighScore();
	outFile.close();
}
