#include"Ball.h"
void Ball::move(sf::Time deltaTime) {
	
	if (active) {
		//propx = 0;
		//propy = 1;
		
	}
	sprite.move(velocity*propx*deltaTime.asSeconds()*directionX,velocity*propy*deltaTime.asSeconds()*directionY);
}
void Ball::contactPlayer(){
	float magnitudX;
	if (sprite.getPosition().x > player->sprite.getPosition().x + player->sprite.getLocalBounds().width / 2) {
	//	cout << "parte derecha direccion positiva";
		directionX = 1;
		directionY = -1;
		float n = player->sprite.getPosition().x + player->sprite.getLocalBounds().width / 2;
		magnitudX = sprite.getPosition().x - n;
		//cout << "pos bola x " << sprite.getPosition().x;
		//cout << "pos mitad tabla " << n;
		//cout << "magnitud " << magnitudX;
		//cout << "magnitud max " << player->sprite.getLocalBounds().width / 2;
		//magnitudX *= 100;
		magnitudX = magnitudX / player->sprite.getLocalBounds().width;
		//cout << "propx " << magnitudX;
		//propx = magnitudX/100;
		propx = magnitudX;
		propy = 1 - magnitudX;
		//cout << "propy " << propy;

		

	}
	else {
		cout << "parte izquierda direccion xnegativa";
		directionX = -1;
		directionY =- 1;
		float n =player->sprite.getPosition().x + player->sprite.getLocalBounds().width / 2;
		magnitudX = n - sprite.getPosition().x;
		magnitudX=magnitudX/ player->sprite.getLocalBounds().width;
		propx = magnitudX;
		propy = 1 - propx;
	
	}
	


}
void Ball::update(sf::Time deltaTime){
	if (player->activeShoot&&active==false) {
		active = true;
		propx = 0;
		propy = 1;
		player->activeShoot = false;
		player->soundColision.play();
		cout << "activando bola" << endl;
	}
	if (active == false) {
		//para q siga al player
		sprite.setPosition(player->sprite.getPosition().x + player->sprite.getLocalBounds().width / 2 - sprite.getLocalBounds().width / 2, player->sprite.getPosition().y - sprite.getLocalBounds().height);
	}
	if (sprite.getPosition().y + sprite.getGlobalBounds().height > dimensionsScene.height&&!dead) {
		dead = true;
		player->currentLifes--;
		player->activeAnimation = true;
	}
	if (player->respawnBall) {
		dead = false;
		sprite.setPosition(player->sprite.getPosition().x + player->sprite.getLocalBounds().width / 2 - sprite.getLocalBounds().width / 2, player->sprite.getPosition().y - sprite.getLocalBounds().height);
		active = false;
		player->respawnBall = false;
	}
	
	move(deltaTime);

}

void Ball::draw() {
	if(!dead)
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
active(false), velocity(450), directionY(-1), directionX(1), propx(0), propy(0), dead(false)
{
	init();
}
Ball::~Ball(){}