#ifndef LIVELLO_H
#define LIVELLO_H

#include "Block.h"

using namespace std;

class Livello
{
public:
  Livello();
  Block** creaLivello(int[8][12]);
private:
  Block** livello;
};
#endif
