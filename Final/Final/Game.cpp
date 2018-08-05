#include"Game.h"


void Game::run() {
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		//std::cout << deltaTime.asSeconds() << endl;
		processEvents();
		update(deltaTime);
		render();
	}
}
void Game::update(sf::Time deltaTime){
	player->move(deltaTime);
	ball->update(deltaTime);
	collision->collideBallBoundarys();
	collision->collideBallPlayer();
	collision->collideBallBricks();
}
void Game::processEvents() {
	sf::Event event;

	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			player->handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			player->handlePlayerInput(event.key.code, false);
			break;

		}

	}
}

void Game::render() {
	window.clear();
	//DIBUJO
	scene->draw();
	player->draw();
	bricks->draw();
	ball->draw();
	window.display();
}
Game::~Game() {
	delete player;
	delete scene;
	delete ball;
	delete bricks;
	delete collision;
}
Game::Game(){
//window.create(sf::VideoMode(widthScene,heightScene), "ARKANOID");
window.create(sf::VideoMode::getFullscreenModes()[0], "ARKANOID", sf::Style::Fullscreen);
scene = new Scene(&window);
player = new Player(&window,scene->dimensions);
ball = new Ball(&window, scene->dimensions, player);
bricks = new Bricks(&window, scene->dimensions);
collision = new Collision(ball, scene,player,bricks);
run();
}