#include"Buttons.h"
void Buttons::setDimensionsSceneMenu(sf::Vector2f vec, float _widthScene, float _heightScene) {
	dimensionsScene = vec;
	widthScene = _widthScene;
	heightScene = _heightScene;
	buttonPlay.setPosition(dimensionsScene.x + widthScene / 2 - buttonPlay.getLocalBounds().width / 2, buttonPlay.getLocalBounds().height + 120);
	buttonCredits.setPosition(buttonPlay.getPosition().x + buttonPlay.getLocalBounds().width / 2 - buttonCredits.getLocalBounds().width / 2, buttonPlay.getPosition().y + buttonPlay.getLocalBounds().height + 30);
	buttonExit.setPosition(buttonCredits.getPosition().x + buttonCredits.getLocalBounds().width / 2 - buttonExit.getLocalBounds().width / 2, buttonCredits.getPosition().y + buttonCredits.getLocalBounds().height + 30);
	buttonMenu.setPosition(dimensionsScene.x + widthScene - buttonMenu.getLocalBounds().width, dimensionsScene.y + heightScene - buttonMenu.getLocalBounds().height);
}
void Buttons::draw(){
	if (drawMenuButtons) {
		window->draw(buttonPlay);
		window->draw(buttonCredits);
		window->draw(buttonExit);
	}
	if (drawCreditsButtons) {
		window->draw(buttonMenu);
	}
}
bool Buttons::collideEnter(sf::Sprite sprite) {
	sf::Vector2i vec = sf::Mouse::getPosition();
	if (vec.x > sprite.getPosition().x&&vec.x<sprite.getPosition().x + sprite.getLocalBounds().width&&vec.y>sprite.getPosition().y&&vec.y < sprite.getPosition().y + sprite.getLocalBounds().height) {
		return true;
	}
	return false;
}
void Buttons::update(sf::Time deltaTime){
		detectStates(buttonPlay, vecTexturePlay[0], vecTexturePlay[1], vecTexturePlay[2], applyTexture, state, deltaTime, currentState::start);

		detectStates(buttonCredits, vecTextureCredits[0], vecTextureCredits[1], vecTextureCredits[2], apply2, state, deltaTime, currentState::credits);

	detectStates(buttonExit, vecTextureExit[0], vecTextureExit[1], vecTextureExit[2], apply3, state, deltaTime, currentState::exit);

	detectStates(buttonMenu, vecTextureMenu[0], vecTextureMenu[1], vecTextureMenu[2], apply4, state, deltaTime, currentState::menu);

 
}
void Buttons::detectStates(sf::Sprite& sprite, sf::Texture& textOut, sf::Texture& textOver, sf::Texture& textPress, bool& apply, currentState& _state, sf::Time delta, currentState objState) {
	if (startState) {
		timer += delta.asSeconds();
		if (timer > 2.5f) {


			switch (_state)
			{
			case currentState::start:
				goGame = true;
				startState = false;
				timer = 0;
				break;
			case currentState::credits:
			
				goCredits = true;
				timer = 0;
				startState = false;
				break;
			case currentState::menu:
				goCredits = false;
				timer = 0;
				startState = false;
				break;
			case currentState::exit:
				timer = 0;
				startState = false;
				window->close();
				break;
			}
		}
	}
	if (collideEnter(sprite)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			cout << "click" << endl;
			press = true;
			if (press) {
				//click en el boton

				startState = true;
				sprite.setTexture(textPress);
				press = false;
				apply = true;
				_state = objState;
			}
		}
		else {
			if (!apply) {
				sprite.setTexture(textOver);
				apply = true;
			}
		}
	}
	else if (apply) {
		sprite.setTexture(textOut);
		apply = false;
	}
}
void Buttons::setTexturesButtons() {
	for (int i = 0; i < 3; i++) {
		sf::Texture texture;
		sf::Texture texture2;
		sf::Texture texture3;
		sf::Texture texture4;
		switch (i)
		{
		case 0:
			if (!texture.loadFromFile("Assets/Buttons/buttonPlay_1.png") || !texture2.loadFromFile("Assets/Buttons/buttonCredits_1.png") || !texture3.loadFromFile("Assets/Buttons/buttonExit_1.png") || texture4.loadFromFile("Assets/Buttons/buttonsMenu_1.png")) {
				cout << "textura no cargada menu";
			}
			vecTexturePlay.push_back(texture);
			vecTextureCredits.push_back(texture2);
			vecTextureExit.push_back(texture3);
			vecTextureMenu.push_back(texture4);
			break;
		case 1:
			if (!texture.loadFromFile("Assets/Buttons/buttonPlay_2.png") || !texture2.loadFromFile("Assets/Buttons/buttonCredits_2.png") || !texture3.loadFromFile("Assets/Buttons/buttonExit_2.png") || texture4.loadFromFile("Assets/Buttons/buttonsMenu_2.png")) {
				cout << "textura no cargada menu";
			}
			vecTexturePlay.push_back(texture);
			vecTextureCredits.push_back(texture2);
			vecTextureExit.push_back(texture3);
			vecTextureMenu.push_back(texture4);
			break;
		case 2:
			if (!texture.loadFromFile("Assets/Buttons/buttonPlay_3.png") || !texture2.loadFromFile("Assets/Buttons/buttonCredits_3.png") || !texture3.loadFromFile("Assets/Buttons/buttonExit_3.png") || texture4.loadFromFile("Assets/Buttons/buttonsMenu_3.png")) {
				cout << "textura no cargada menu";
			}
			vecTexturePlay.push_back(texture);
			vecTextureCredits.push_back(texture2);
			vecTextureExit.push_back(texture3);
			vecTextureMenu.push_back(texture4);
			break;
		}
	}
}
void Buttons::init() {
	setTexturesButtons();
	buttonPlay.setTexture(vecTexturePlay[0]);
	buttonCredits.setTexture(vecTextureCredits[0]);
	buttonExit.setTexture(vecTextureExit[0]);
	buttonMenu.setTexture(vecTextureMenu[0]);


	
}
Buttons::Buttons(sf::RenderWindow* _window) :window(_window), drawMenuButtons(false), drawCreditsButtons(false), timer(0), applyTexture(false), apply2(false), apply3(false),
apply4(false), press(false), goCredits(false), startState(false),goGame(false),widthScene(0),heightScene(0)
{
	init();
}
Buttons::~Buttons(){
}