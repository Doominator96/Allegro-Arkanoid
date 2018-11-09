#include "Vaus.h"

Vaus::Vaus()
{
  x_init=348;
  y_init=560;
  lives=3;
  x=348;
  y=560;
  score=0;
}
void Vaus::vausReset(){
  x=x_init;
  y=y_init;
}
