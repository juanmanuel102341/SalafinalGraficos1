#ifndef BUTTONS_H
#define BUTTONS_H
#include<vector>
#include<iostream>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
using namespace std;
class Buttons
{
public:
	enum currentState {
		start, credits, exit, menu, replay
	};
	Buttons(sf::RenderWindow* _window);
	void update(sf::Time deltaTime);
	~Buttons();
	void setDimensionsSceneMenu(sf::Vector2f dim,float widthScene,float heightScene);

	bool drawMenuButtons;
	bool drawCreditsButtons;
	bool drawFinalGuiState;
	bool goCredits;
	bool goGame;
	bool goReplay;
	bool startState;
	void draw();
private:
	void setTexturesButtons();
	void init();
	bool collideEnter(sf::Sprite sprite);
	void detectStates(sf::Sprite& sprite, sf::Texture& textOver, sf::Texture& textPress, sf::Texture& textOut, bool& apply, currentState& state, sf::Time delta, currentState objState);
	sf::Vector2f dimensionsScene;
	float widthScene;
	float heightScene;
	std::vector<sf::Texture>vecTexturePlay;
	std::vector<sf::Texture>vecTextureCredits;
	std::vector<sf::Texture>vecTextureExit;
	std::vector<sf::Texture>vecTextureMenu;
	std::vector<sf::Texture>vecTextureReplay;
	
	sf::Texture currentTexturePlay;
	sf::Texture currentTextureCredits;
	sf::Texture currentTextureExit;
	sf::Texture currentTextureMenu;
	sf::Texture currentTecturePlay
		;
	sf::Sprite buttonPlay;
	sf::Sprite buttonCredits;
	sf::Sprite buttonExit;
	sf::Sprite buttonMenu;
	sf::Sprite buttonReplay;
	currentState state;
	sf::RenderWindow* window;


	float timer;

	bool applyTexture;
	bool apply2;
	bool apply3;
	bool apply4;
	bool apply5;
	bool press;
};
#endif // !BUTTONS_H
