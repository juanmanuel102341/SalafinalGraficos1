#include"FinalGuiStates.h"

void FinalGuiStates::update(sf::Time delta) {
	/*if (!win) {
		if (!applyFinal) {
			buttons->drawFinalGuiState = true;
			buttons->drawCreditsButtons = false;
			buttons->drawMenuButtons = false;
			buttons->setDimensionsSceneMenu(spriteWin.getPosition(), spriteWin.getLocalBounds().width, spriteWin.getLocalBounds().height);
			applyFinal = true;
		}
		buttons->update(delta);
	}
	else {

	}
	*/
}
void FinalGuiStates::setDimensions(sf::Vector2f _dimensions, float _width, float _height) {
	dimensions = _dimensions;
	widhtScene = _width;
	heightScene = _height;
	spriteLoose.setPosition(dimensions.x + 100, dimensions.y + _height / 2 - spriteLoose.getLocalBounds().height / 2 - 75);
	spriteWin.setPosition(dimensions.x + 100, dimensions.y + _height / 2 - spriteWin.getLocalBounds().height / 2 - 75);
}

void FinalGuiStates::init() {
	if (!textureWin.loadFromFile("Assets/levelComplete.png")||textureLoose.loadFromFile("Assets/Loose.png")) {
		cout << "asset no cargado final gui";
	}
	spriteWin.setTexture(textureWin);
	spriteLoose.setTexture(textureLoose);
//	buttons = new Buttons(window);
	
}
void FinalGuiStates::draw(){
	if (win) {
		window->draw(spriteWin);
//		buttons->draw();
	}
	else {
		window->draw(spriteLoose);
	//	buttons->draw();
	}
}


FinalGuiStates::FinalGuiStates(sf::RenderWindow* _window ):window(_window), widhtScene(0), heightScene(0),applyFinal(false) {
	init();
}
FinalGuiStates::~FinalGuiStates() {

}