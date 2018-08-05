#include"Collision.h"
void Collision::collideBallBoundarys() {
	if (ball->sprite.getGlobalBounds().intersects(scene->colliderUp.getGlobalBounds())) {
	//	cout << "colsion limite superior" << endl;
		scene->soundEfectColision.play();
		ball->directionY *= -1;
		
	}
	if (ball->sprite.getGlobalBounds().intersects(scene->colliderleft.getGlobalBounds())||ball->sprite.getGlobalBounds().intersects(scene->colliderRight.getGlobalBounds())) {
		scene->soundEfectColision.play();
		ball->directionX *= -1;
	}
}
void Collision::collideBallPlayer() {
	if (player->sprite.getGlobalBounds().intersects(ball->sprite.getGlobalBounds())) {
	//	cout << "colision player" << endl;
		player->soundColision.play();
		ball->contactPlayer();
		
	}
}
void Collision::collideBallBricks() {
	for (int i = 0; i < bricks->Vecbricks.size(); i++) {
		sf::Sprite spriteBrick=bricks->Vecbricks[i]->sprite;
	
		if (ball->sprite.getPosition().x + ball->sprite.getLocalBounds().width>spriteBrick.getPosition().x
			&&ball->sprite.getPosition().x < spriteBrick.getPosition().x + spriteBrick.getLocalBounds().width
			&&ball->sprite.getPosition().y < spriteBrick.getPosition().y + spriteBrick.getLocalBounds().height
			&&ball->sprite.getPosition().y+ball->sprite.getGlobalBounds().height>spriteBrick.getPosition().y	 )
		{
		//contacto por x abajo
			bricks->soundColision.play();
			ball->directionY *= -1;
			bricks->Vecbricks.erase(bricks->Vecbricks.begin() + i);
			break;
		}
		
	if (ball->sprite.getPosition().y + ball->sprite.getLocalBounds().height>spriteBrick.getPosition().y
			&&ball->sprite.getPosition().y<spriteBrick.getPosition().y + spriteBrick.getLocalBounds().height
			&&ball->sprite.getPosition().x + ball->sprite.getLocalBounds().width>spriteBrick.getPosition().x
			&&ball->sprite.getPosition().x<spriteBrick.getPosition().x+spriteBrick.getLocalBounds().width) {
		//contacto por el costado	
			bricks->soundColision.play();
			ball->directionX *= -1;
			bricks->Vecbricks.erase(bricks->Vecbricks.begin() + i);
		
			//bricks->Vecbricks.erase(bricks->Vecbricks.begin() + i);
			
			break;
		}
	
	}
	
	}
Collision::Collision(Ball* _ball, Scene* _scene,Player* _player,Bricks* _bricks): ball(_ball),scene(_scene),player(_player),bricks(_bricks) {

}
Collision::~Collision(){}