#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <vector>
#include <iostream>
#include "Block.h"
#include "Livello.h"
#include "Vaus.h"
#include "Ball.h"

using namespace std;

class GestoreGioco
{
	public:
		GestoreGioco();
		void draw(int lvl);
		const int getNumLivelli(){return numLivelli;}
		 vector<Block**> getLivelli(){return livelli;}
		 vector<ALLEGRO_BITMAP*> getBlocks(){return blocks;}
		 void movimento(Vaus v);
		 ALLEGRO_BITMAP* ball;
		 Ball b;
		 void collisionControl(Vaus v, int lvl);
  private:
		int numLivelli;
    vector<Block**> livelli;
		vector<ALLEGRO_BITMAP*> blocks;
		ALLEGRO_BITMAP* paddle;
		Vaus v;
		ALLEGRO_BITMAP* bg;
		int dx;
		int dy;
};




#endif
