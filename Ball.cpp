#include "Ball.h"

void Ball::movements(){

x+=dx;
y-=dy;
}
void Ball::ballReset(){
  x=x_init;
  y=y_init;
  dy=3;
}
