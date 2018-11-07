#include "Enemy.h"

Enemy::Enemy(){
  x_init=0;
  y_init=0;
  x=0;
  y=0;
  dX=2;
  dY=2;
  alive=true;
}
void Enemy::enemyReset(){
  x=x_init;
  y=y_init;
}
void Enemy::movements(){

x-=dX;
y-=dY;
}
