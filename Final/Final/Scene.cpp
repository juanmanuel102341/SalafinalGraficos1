#include"Scene.h"

void Scene::draw(){
	window->draw(sprite);
	window->draw(colliderUp);
	window->draw(colliderleft);
	window->draw(colliderRight);
	
}

void Scene::init(){
	if (!texture.loadFromFile("assets/gameArea.png")) {
		std::cout << "error";
	};
	if (!bufferEfectColision.loadFromFile("assets/Sounds/zapBoundary.wav")||!bufferEfectWin.loadFromFile("assets/Sounds/win.wav")) {
		std::cout << "error loaded sound efect scene";
	}
	soundEfectColision.setBuffer(bufferEfectColision);
	soundWin.setBuffer(bufferEfectWin);
	sprite.setTexture(texture);
	sprite.setPosition(sf::VideoMode::getDesktopMode().width / 2 - sprite.getLocalBounds().width / 2, sf::VideoMode::getDesktopMode().height/2 - sprite.getLocalBounds().height / 2);
	dimensions.origin = sprite.getPosition();
	dimensions.origin.x += 39;
	dimensions.origin.y += 36;
	dimensions.width = sprite.getPosition().x + sprite.getLocalBounds().width;
	dimensions.width -= 36;
	dimensions.half = sprite.getPosition().x + sprite.getLocalBounds().width / 2;
	dimensions.height = sprite.getPosition().y + sprite.getLocalBounds().height;

	colliderUp.setSize(sf::Vector2f(sprite.getLocalBounds().width,40));
	colliderUp.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	colliderUp.setFillColor(sf::Color::Transparent);

	colliderleft.setSize(sf::Vector2f(40, sprite.getLocalBounds().height));
	colliderleft.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	colliderleft.setFillColor(sf::Color::Transparent);
	
	
	colliderRight.setSize(sf::Vector2f(40, sprite.getLocalBounds().height));
	colliderRight.setPosition(sprite.getPosition().x + sprite.getLocalBounds().width-38, sprite.getPosition().y);
	colliderRight.setFillColor(sf::Color::Transparent);
	
	
	

}
Scene::~Scene(){
	
}
Scene::Scene(sf::RenderWindow* _window): window(_window),levelPass(false),loose(false){
	init();
}
