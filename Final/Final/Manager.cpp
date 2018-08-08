#include"Manager.h"
void Manager::resetlevel() {
	bricks->Vecbricks.clear();
	bricks->initialBricks();
	player->resetState();
	player->currentLifes = player->totalLifes;
	scene->loose = false;
	scene->levelPass = false;

}
void Manager::draw(){
	if (scene->loose) {
		window->draw(spriteLoose);
	}
	if (scene->levelPass) {
		window->draw(spriteWin);
	}
}
void Manager::update(sf::Time deltaTime){
	if (player->debugWin) {
		bricks->Vecbricks.clear();
	}
	
	if (scene->loose) {
		
		if (player->reset) {
			resetlevel();
		}
		if (player->menu) {
			resetlevel();
			menu->startGame = false;
		}
	
		
	}
	if (scene->levelPass) {
		if (!clean) {
			//player->finalLevel = true;
			//player->currentLifes = 0;
			//player->dead=true;
		//	ball->dead = true;
			//ball->sprite.setPosition(1000, 1000);
			clean = true;
		}
		if (player->reset) {
		//	player->finalLevel = false;
			//player->dead = false;
		//	ball->dead = false;
		//	clean = false;
			resetlevel();
		}
		if (player->menu) {
			//player->finalLevel = false;
			//player->dead = false;
		//	ball->dead = false;
		//	clean = false;
			resetlevel();
			menu->startGame = false;
		}
		
	}

}
void Manager::init() {
	if (!textureLoose.loadFromFile("Assets/Loose.png") || !textureWin.loadFromFile("Assets/levelComplete.png")) {
		cout << "error textura no cargada";
	}
	spriteLoose.setTexture(textureLoose);
	spriteWin.setTexture(textureWin);

	spriteLoose.setPosition(scene->dimensions.origin.x+100, scene->dimensions.origin.y + scene->dimensions.height / 2-spriteLoose.getLocalBounds().height/2);
	spriteWin.setPosition(scene->dimensions.origin.x + 100, scene->dimensions.origin.y + scene->dimensions.height / 2 - spriteWin.getLocalBounds().height / 2);
}
Manager::Manager(Player* _player, Bricks* _bricks, Scene* _scene,sf::RenderWindow* _window, Menu* _menu,Ball* _ball ) : player(_player), bricks(_bricks), scene(_scene),window(_window),menu(_menu),clean(false),ball(_ball) {
	init();
}
Manager::~Manager(){}