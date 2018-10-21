#ifndef BALL_H
#define BALL_H

class Ball{
public:
  Ball():x_init(389),y_init(530),x(389),y(530),dx(3),dy(3){};
  int getX() const {return x;}
  void setX(int _x) {x=_x;}
  int getY() const {return y;}
  void setY(int _y) {y=_y;}
  void movements();

  int getXInit() const {return x_init;}
  int getYInit() const {return y_init;}

  int getDx() const {return dx;}
  void setDx(int _dx) {dx=_dx;}
  int getDy() const {return dy;}
  void setDy(int _dy) {dy=_dy;}

  void ballReset();
private:
  int x_init;
  int y_init;
  int x;
  int y;
  int dx;
  int dy;
};
#endif
