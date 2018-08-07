#include"Game.h"


void Game::run() {
	sf::Clock clock;

	//musicLevel.play();
	
//	musicLevel.setLoop(true);
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
	if (menu->startGame) {
		player->move(deltaTime);
		player->update(deltaTime);
		ball->update(deltaTime);
		collision->collideBallBoundarys();
		collision->collideBallPlayer();
		collision->collideBallBricks();
		manager->update(deltaTime);
	}
	else {
		//menu
		menu->update(deltaTime);
	}
}
void Game::processEvents() {
	sf::Event event;

	while (window.pollEvent(event)) {
		
		if (menu->startGame) {
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
		else {
			//mennu
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				break;
			}
		}
	}

	
}

void Game::render() {
	if (menu->startGame) {
		window.clear();
		//DIBUJO
		scene->draw();
		player->draw();
		bricks->draw();
		ball->draw();
		window.display();
	}
	else {
		//menu
		window.clear();
		menu->draw();

		window.display();
	}
}
Game::~Game() {
	delete player;
	delete scene;
	delete ball;
	delete bricks;
	delete collision;
	delete manager;
	delete menu;
	delete buttons;
}
Game::Game(){
//window.create(sf::VideoMode(widthScene,heightScene), "ARKANOID");
window.create(sf::VideoMode::getFullscreenModes()[0], "ARKANOID", sf::Style::Fullscreen);
buttons = new Buttons(&window);
menu = new Menu(&window,buttons);
scene = new Scene(&window);
player = new Player(&window,scene);
ball = new Ball(&window, scene->dimensions, player);
bricks = new Bricks(&window, scene->dimensions);
collision = new Collision(ball, scene,player,bricks);
manager = new Manager(player, bricks, scene);
if (!musicLevel.openFromFile("assets/Sounds/music.wav")) {
	std::cout << "error loaded music wav";
}
run();
}