#include"Bricks.h"

void Bricks::draw(){
	for (int i = 0; i < numberOfBricks*numberOfLines; i++) {
		window->draw(Vecbricks[i]->sprite);
	}
}
sf::Texture Bricks::returnTexture(int id) {
	switch (id)
	{
	case 0:
		
		return textureBlue;
		break;
	case 1:
		
		return textureRed;
		break;
	}
}
void Bricks::init(){
	int gapX=15;
	int gapY = 20;
	int sumX = 0;
	int sumY = 0;
	int heightBrick;
	if (!textureBlue.loadFromFile("assets/brickBlue.png")|| !textureRed.loadFromFile("assets/brickRed.png")||!textureGreen.loadFromFile("assets/brickGreen.png")||!textureBrown.loadFromFile("assets/brickBrown.png")) {
		std::cout << "error charge texture";
	}
	
	currentTexture = textureBlue;
	for (int i0 = 0; i0 < numberOfLines; i0++) {
	
		sumX = 0;
		for (int i = 0; i < numberOfBricks; i++) {
			Brick* brick = new Brick;
			brick->texture = currentTexture;
			brick->sprite.setTexture(brick->texture);
			brick->position.x = dimensions.origin.x + 50 + sumX;
			brick->position.y = dimensions.origin.y + 50+sumY;
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
Bricks::Bricks(sf::RenderWindow* _window, DimensionsScene _dimensionsScene): window(_window),dimensions(_dimensionsScene) {
	init();
}