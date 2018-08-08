#include"Menu.h"



void Menu::update(sf::Time deltaTime) {
	
	buttons->update(deltaTime);
	if (buttons->goCredits) {
		buttons->drawMenuButtons = false;
		buttons->drawCreditsButtons = true;
		
	}
	else {
		buttons->drawCreditsButtons = false;
		buttons->drawMenuButtons = true;
		if (buttons->goGame) {
			startGame = true;
		}
	}
}

void Menu::draw(){
	if (buttons->goCredits) {
		window->draw(spriteCredits);
	}
	else
	{
		window->draw(backMenu);
	}
	
	buttons->draw();
}

void Menu::init() {

	if (!textureBackMenu.loadFromFile("Assets/MenuBase.png") || textureCredits.loadFromFile("Assets/credits.png")) {
		cout << "textura menu no cargada";
	}

	backMenu.setTexture(textureBackMenu);
	spriteCredits.setTexture(textureCredits);
	backMenu.setPosition(sf::VideoMode::getDesktopMode().width / 2 - backMenu.getLocalBounds().width / 2, sf::VideoMode::getDesktopMode().height / 2 - backMenu.getLocalBounds().height / 2);
	spriteCredits.setPosition(sf::VideoMode::getDesktopMode().width / 2 - spriteCredits.getLocalBounds().width / 2, sf::VideoMode::getDesktopMode().height / 2 - spriteCredits.getLocalBounds().height / 2);
	buttons->setDimensionsSceneMenu(backMenu.getPosition(), backMenu.getLocalBounds().width, backMenu.getLocalBounds().height);
	buttons->drawMenuButtons = true;
	
}
Menu::Menu(sf::RenderWindow* _window,Buttons* _buttons): window(_window),mousseDown(false),buttons(_buttons) {
	init();
}
Menu::~Menu() {

}