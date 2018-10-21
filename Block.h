#ifndef BLOCK_H
#define BLOCK_H

#include <allegro5/allegro.h>

using namespace std;

class Block
{
private:
  int color;
  int lives;
public:
  Block():color(0),lives(0){};
  Block(int c,int l){color=c; lives=l;}
  const int getColor(){return color;}
  const int getLives(){return lives;}
  void setLives(int l){lives=l;}
};
#endif
