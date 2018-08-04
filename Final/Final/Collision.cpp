#include"Collision.h"
void Collision::collideBallBoundarys() {
	if (ball->sprite.getGlobalBounds().intersects(scene->colliderUp.getGlobalBounds())) {
		cout << "colsion limite superior" << endl;
		ball->directionY *= -1;
		
	}
	if (ball->sprite.getGlobalBounds().intersects(scene->colliderleft.getGlobalBounds())||ball->sprite.getGlobalBounds().intersects(scene->colliderRight.getGlobalBounds())) {
		ball->directionX *= -1;
	}
}
void Collision::collideBallPlayer() {
	if (player->sprite.getGlobalBounds().intersects(ball->sprite.getGlobalBounds())) {
		cout << "colision player" << endl;
		
		ball->contactPlayer();
	}
}
Collision::Collision(Ball* _ball, Scene* _scene,Player* _player): ball(_ball),scene(_scene),player(_player) {

}
Collision::~Collision(){}