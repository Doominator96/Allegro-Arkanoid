#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <vector>
#include <iostream>
#include <time.h>
#include "Block.h"
#include "Livello.h"
#include "Vaus.h"
#include "Ball.h"
#include "Enemy.h"

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
		 // vector<int> getLivesSum() const {return livesSum;}
		 // void setLivesSum(vector<int> _livesSum){livesSum=_livesSum;}
		 void enemyMove(Enemy* &en,int lvl);
		 bool getCompletato() const {return completato;}
	private:
		int numLivelli;
    vector<Block**> livelli;
		vector<ALLEGRO_BITMAP*> blocks;
		ALLEGRO_BITMAP* paddle;
		vector<ALLEGRO_BITMAP*> enemies;
		Vaus v;
		ALLEGRO_BITMAP* bg;
		int dx;
		int dy;
		int livesSum[4];
		bool cancellato=false;
		bool completato=false;
};




#endif
