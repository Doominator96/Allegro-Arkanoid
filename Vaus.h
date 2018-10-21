#ifndef VAUS_H
#define VAUS_H

class Vaus
{
public:
  Vaus();
  Vaus(int xI, int yI, int _x, int l);
  int getX() const {return x;}
  void setX(int _x) {x=_x;}
  int getY() const {return y;}
  void setY(int _y) {y=_y;}
  int getLives() const {return lives;}
  void setLives(int _lives) {lives=_lives;}

  void vausReset();
private:
  int x_init;
  int y_init;
  int x;
  int y;
  int lives;
};
#endif
