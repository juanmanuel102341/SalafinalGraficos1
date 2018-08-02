#ifndef GAME_H
#define GAME_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
const int widthScene=800;
const int HeightScene=600;
class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void update(sf::Time deltaTime);
	void processEvents();
	void render();
	sf::RenderWindow window;
};

#endif // !GAME_H

