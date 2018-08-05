#include"Player.h"
void Player::draw(){
	if(!dead)
	window->draw(sprite);

}
void Player::animationDead(sf::Time deltaTime) {
	timer += deltaTime.asSeconds();
	if (timer > 0.2f&&dead==false) {
		if (contador == 0) {
			soundLoose.play();
		}
		sprite.setTexture(vecTextureAnimation[contador]);
		contador++;
		timer = 0;
		if (contador == vecTextureAnimation.size() - 1) {
			dead = true;
			contador = 0;
			
		}
		
	}
}
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
	if (key == sf::Keyboard::Right) {
		right = isPressed;
	}
	if (key == sf::Keyboard::Left) {
		left = isPressed;
	}
	if (key == sf::Keyboard::Space) {
		activeShoot = isPressed;
	//	cout << "activando disparo";
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
	initTextureAnimation();
	if (!texture.loadFromFile("assets/playerNormal.png")) {
		std::cout << "error";
	};
	if (!soundBuffer.loadFromFile("assets/Sounds/zapPlayer.wav")||!soundBufferEfectLoose.loadFromFile("assets/Sounds/loose.wav")) {
		std::cout << "error al cargar el sonido";
	}
	soundColision.setBuffer(soundBuffer);
	soundLoose.setBuffer(soundBufferEfectLoose);
	sprite.setTexture(texture);
	sprite.setPosition(dimensionsScene.half-sprite.getLocalBounds().width/2,dimensionsScene.height-sprite.getLocalBounds().height);
//sprite.setPosition(dimensionsScene.width-sprite.getGlobalBounds().width, dimensionsScene.height - sprite.getLocalBounds().height);

}
void Player::initTextureAnimation(){
	for (int i = 0; i < 5; i++) {
		sf::Texture text;
		switch (i)
		{
		case 0:
			text.loadFromFile("assets/Animations/playerNormal_1.png");
			vecTextureAnimation.push_back(text);
			break;
		case 1:
			text.loadFromFile("assets/Animations/playerNormal_2.png");
			vecTextureAnimation.push_back(text);
			break;
		case 2:
			text.loadFromFile("assets/Animations/playerNormal_3.png");
			vecTextureAnimation.push_back(text);
			break;
		case 3:
			text.loadFromFile("assets/Animations/playerNormal_4.png");
			vecTextureAnimation.push_back(text);
			break;
		case 4:
			text.loadFromFile("assets/Animations/playerNormal_5.png");
			vecTextureAnimation.push_back(text);
			break;
		}
	}
}
Player::~Player(){}
Player::Player(sf::RenderWindow* _window,DimensionsScene _dimensions)
	: window(_window), velocity(450),dimensionsScene(_dimensions),activeShoot(false),dead(false),
	contador(0)
{
	initialize();
}