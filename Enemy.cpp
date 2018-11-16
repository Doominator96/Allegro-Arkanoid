#include "Enemy.h"

Enemy::Enemy(){

  srand(time(NULL));
  x_init=0;
  y_init=0;
  x=rand()% 500+100;
  y=20;
  dX=rand()% 4+1;
  dY=rand()%4+1;
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
