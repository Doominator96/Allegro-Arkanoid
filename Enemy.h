#ifndef ENEMY_H
#define ENEMY_H

#include<time.h>
#include<cstdlib>
#include<iostream>
using namespace std;

class Enemy
{
public:
  Enemy();
  Enemy(int xI, int yI, int _x, int l);
  int getX() const {return x;}
  void setX(int _x) {x=_x;}
  int getY() const {return y;}
  void setY(int _y) {y=_y;}
  void setDx(int _dX){dX=_dX;}
  void setDy(int _dY){dY=_dY;}
  int getDx() const {return dX;}
  int getDy() const {return dY;}
  void enemyReset();
  void movements();
  bool getAlive() const {return alive;}
  void setAlive(bool _alive){alive=_alive;}
private:
  bool alive;
  int x_init;
  int y_init;
  int x;
  int y;
  int dX,dY;
};
#endif
