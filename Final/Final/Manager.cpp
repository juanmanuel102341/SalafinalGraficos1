#include"Manager.h"
void Manager::resetlevel() {
	bricks->Vecbricks.clear();
	bricks->initialBricks();
	player->resetState();
	player->currentLifes = player->totalLifes;
}
void Manager::update(sf::Time deltaTime){
	if (scene->loose) {
		if (player->reset) {
			resetlevel();
		}
		
	}
	if (scene->levelPass) {
		if (player->reset) {
			resetlevel();
		}
				
	}

}
Manager::Manager(Player* _player, Bricks* _bricks, Scene* _scene): player(_player),bricks(_bricks), scene(_scene) {

}
Manager::~Manager(){}