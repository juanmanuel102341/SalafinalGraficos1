#include"LevelCompleteState.h"

void LevelCompleteState::setDimensions(sf::Vector2f _dimensions, float _width, float _height) {
	dimensions = _dimensions;
	widhtScene = _width;
	heightScene = _height;
	sprite.setPosition(dimensions.x+100, dimensions.y+_height/2-sprite.getLocalBounds().height/2-75);
}
void LevelCompleteState::draw(){
	window->draw(sprite);
}
void LevelCompleteState::update(sf::Time delta){

}
void LevelCompleteState::init() {
	texture.loadFromFile("Assets/levelComplete.png");
	sprite.setTexture(texture);
	
}
LevelCompleteState::LevelCompleteState(sf::RenderWindow* _window):window(_window),widhtScene(0),heightScene(0){
	init();
}
LevelCompleteState::~LevelCompleteState() {

}