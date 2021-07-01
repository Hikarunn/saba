#include "Player.h"
#include"Enemy.h"

Player::Player() {
	enemy_ = new  Enemy();
	enemy_->Out();
}