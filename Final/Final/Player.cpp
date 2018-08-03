#include"Player.h"
void Player::draw(){
	window->draw(sprite);

}
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
	if (key == sf::Keyboard::Right) {
		right = isPressed;
	}
	if (key == sf::Keyboard::Left) {
		left = isPressed;
	}

}
void Player::move(sf::Time deltaTime){
	sf::Vector2f movement(0.f, 0.f);
	if (right&&sprite.getPosition().x+sprite.getLocalBounds().width<dimensionsScene.width) {
		movement.x += velocity;
	}
	if (left&&sprite.getPosition().x>dimensionsScene.origin.x) {
		movement.x -= velocity;
	}
	sprite.move(movement*deltaTime.asSeconds());
}
void Player::initialize(){
	if (!texture.loadFromFile("assets/playerNormal.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	sprite.setPosition(dimensionsScene.half-sprite.getLocalBounds().width/2,dimensionsScene.height-sprite.getLocalBounds().height);
//sprite.setPosition(dimensionsScene.width-sprite.getGlobalBounds().width, dimensionsScene.height - sprite.getLocalBounds().height);

}

Player::~Player(){}
Player::Player(sf::RenderWindow* _window,DimensionsScene _dimensions)
	: window(_window), velocity(450),dimensionsScene(_dimensions)
{
	initialize();
}