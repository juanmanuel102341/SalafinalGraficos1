#ifndef BRICKS_H
#define BRICKS_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
#include"Scene.h"

class Bricks
{
	struct Brick
	{
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Vector2f position;
	};
public:
	const int numberOfBricks=5;
	const int numberOfLines = 5;
	Bricks(sf::RenderWindow* window, DimensionsScene _dimensionsScene);
	~Bricks();
	void draw();
	void takeOutBrick(Brick*brick);
	std::vector<Brick*>Vecbricks;
	sf::Sound soundColision;
private:
	void init();
	sf::RenderWindow* window;
	DimensionsScene dimensions;
	sf::Texture textureBlue;
	sf::Texture textureRed;
	sf::Texture textureBrown;
	sf::Texture textureGreen;
	sf::Texture currentTexture;
	sf::SoundBuffer bufferEfectSound;
};

#endif // !BRICKS_H
