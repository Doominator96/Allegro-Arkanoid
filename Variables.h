#ifndef VARIABLES_H
#define VARIABLES_H

class Variables{
public:
  Variables():mHeight(8),mWidth(12),blockW(64),blockH(32),border(16),numLivelli(2),screenW(800),screenH(600),paddleW(104),scoreIncrement(10),ballDim(22),enemyW(69){}
  int getNumLivelli(){return numLivelli;}
protected:
  int mHeight;
  int mWidth;
  int blockW;
  int blockH;
  int border;
  int numLivelli;
  int screenW;
  int screenH;
  int paddleW;
  int scoreIncrement;
  int ballDim;
};
#endif
