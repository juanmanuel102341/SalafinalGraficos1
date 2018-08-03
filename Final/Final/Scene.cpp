#include"Scene.h"
void Scene::draw(){
	window->draw(sprite);
}
void Scene::init(){
	if (!texture.loadFromFile("assets/gameArea.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	sprite.setPosition(sf::VideoMode::getDesktopMode().width / 2 - sprite.getLocalBounds().width / 2, sf::VideoMode::getDesktopMode().height/2 - sprite.getLocalBounds().height / 2);
	dimensions.origin = sprite.getPosition();
	dimensions.origin.x += 39;
	dimensions.origin.y += 36;
	dimensions.width = sprite.getPosition().x + sprite.getLocalBounds().width;
	dimensions.width -= 36;
	dimensions.half = sprite.getPosition().x + sprite.getLocalBounds().width / 2;
	dimensions.height = sprite.getPosition().y + sprite.getLocalBounds().height;

}
Scene::~Scene(){}
Scene::Scene(sf::RenderWindow* _window): window(_window){
	init();
}
