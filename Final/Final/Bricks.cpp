#include"Bricks.h"

void Bricks::draw(){
	for (int i = 0; i < Vecbricks.size(); i++) {
		window->draw(Vecbricks[i]->sprite);
	}
}

void Bricks::init(){
	
	if (!bufferEfectSound.loadFromFile("assets/Sounds/zapBricks.wav")) {
		std::cout << "error loaded sound efect brick";
	}
	soundColision.setBuffer(bufferEfectSound);
	if (!textureBlue.loadFromFile("assets/brickBlue.png")|| !textureRed.loadFromFile("assets/brickRed.png")||!textureGreen.loadFromFile("assets/brickGreen.png")||!textureBrown.loadFromFile("assets/brickBrown.png")) {
		std::cout << "error charge texture";
	}
	
	initialBricks();
	
}
void Bricks::initialBricks(){
	int gapX = 25;
	int gapY = 45;
	int sumX = 0;
	int sumY = 0;
	int heightBrick;
	currentTexture = textureBlue;
	for (int i0 = 0; i0 < numberOfLines; i0++) {

		sumX = 0;
		for (int i = 0; i < numberOfBricks; i++) {
			Brick* brick = new Brick;
			brick->texture = currentTexture;
			brick->sprite.setTexture(brick->texture);
			brick->position.x = dimensions.origin.x + 100 + sumX;
			brick->position.y = dimensions.origin.y + 50 + sumY;
			brick->sprite.setPosition(brick->position);
			sumX += brick->sprite.getLocalBounds().width + gapX;
			Vecbricks.push_back(brick);
			heightBrick = brick->sprite.getLocalBounds().height;
		}
		sumY += heightBrick + gapY;

		switch (i0)
		{
		case 0:
			currentTexture = textureRed;
			break;
		case 1:
			currentTexture = textureGreen;
			break;
		case 2:
			currentTexture = textureBrown;
			break;
		case 3:
			currentTexture = textureBlue;
			break;
		case 4:
			currentTexture = textureRed;
		}

	}

}
Bricks::~Bricks() {
	for (int i = 0; i < numberOfBricks; i++) {
		Brick*brick = Vecbricks[i];
		delete brick;
	}
}
Bricks::Bricks(sf::RenderWindow* _window, DimensionsScene _dimensionsScene): window(_window),dimensions(_dimensionsScene)

{
	init();
}