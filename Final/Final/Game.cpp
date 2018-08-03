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
	window.display();
}
Game::~Game() {
	delete player;
	delete scene;
}
Game::Game(){
//window.create(sf::VideoMode(widthScene,heightScene), "ARKANOID");
window.create(sf::VideoMode::getFullscreenModes()[0], "ARKANOID", sf::Style::Fullscreen);
scene = new Scene(&window);
player = new Player(&window,scene->dimensions);

run();
}