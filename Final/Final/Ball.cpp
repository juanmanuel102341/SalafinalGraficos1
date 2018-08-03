#include"Ball.h"
void Ball::move(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (active) {
		movement.y -= velocity;
		
	}
	sprite.move(movement*deltaTime.asSeconds());
}
void Ball::update(sf::Time deltaTime){
	if (player->activeShoot&&active==false) {
		active = true;
		player->activeShoot = false;
		cout << "activando bola" << endl;
	}
	move(deltaTime);
}
void Ball::draw() {
	window->draw(sprite);
}
void Ball::init(){
	if (!texture.loadFromFile("assets/ballNormal.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	sprite.setPosition(player->sprite.getPosition().x+player->sprite.getLocalBounds().width/2 - sprite.getLocalBounds().width / 2, player->sprite.getPosition().y - sprite.getLocalBounds().height);
}
Ball::Ball(sf::RenderWindow* _window, DimensionsScene _dimensionsScene, Player* _player) : window(_window), dimensionsScene(_dimensionsScene), player(_player),
active(false),velocity(250)
{
	init();
}
Ball::~Ball(){}