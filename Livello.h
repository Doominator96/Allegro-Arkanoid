#ifndef LIVELLO_H
#define LIVELLO_H

#include "Block.h"

using namespace std;

class Livello
{
public:
  Livello();
  ~Livello();
  Livello(const Livello& l);
  Livello& operator=(const Livello& l);
  Block** creaLivello(int[8][12]);
private:
  Block** livello;
  int mHeight;
  int mWidth;
};
#endif
