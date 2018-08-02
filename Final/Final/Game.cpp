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
	
}
void Game::processEvents() {
	sf::Event event;

	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::render() {
	window.clear();
	//DIBUJO

	window.display();
}
Game::~Game() {

}
Game::Game(){
window.create(sf::VideoMode(widthScene,HeightScene), "ARKANOID");
run();
}