#include"Manager.h"

void Manager::update(sf::Time deltaTime){
	if (scene->loose) {
		if (player->reset) {
			bricks->Vecbricks.clear();
			bricks->initialBricks();
			player->resetState();
			player->currentLifes = player->totalLifes;
		}
		
	}

}
Manager::Manager(Player* _player, Bricks* _bricks, Scene* _scene): player(_player),bricks(_bricks), scene(_scene) {

}
Manager::~Manager(){}