#ifndef LIVELLO_H
#define LIVELLO_H

#include "Block.h"
#include "Variables.h"

using namespace std;

class Livello : public Variables
{
public:
  Livello();
  ~Livello();
  Livello(const Livello& l);
  Livello& operator=(const Livello& l);
  Block** creaLivello(int[8][12]);
private:
  Block** livello;
};
#endif
