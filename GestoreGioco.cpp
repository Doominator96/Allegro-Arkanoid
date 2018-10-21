#include "GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
  dx=1;
  dy=1;
  numLivelli=2;
  Livello l;
  if (!al_init())
  cerr << "No Allegro" << endl;

  blocks.push_back(al_load_bitmap("red.png"));
  blocks.push_back(al_load_bitmap("blue.png"));
  blocks.push_back(al_load_bitmap("green.png"));
  blocks.push_back(al_load_bitmap("silver.png"));
  blocks.push_back(al_load_bitmap("gold.png"));
  bg = al_load_bitmap("back.jpg");
  for (unsigned i = 0; i<blocks.size(); i++)
  if (!blocks[i])
  cerr << "No Blocks bitmap " << endl;

  paddle=al_load_bitmap("paddle.png");
  ball=al_load_bitmap("ball.png");

  int liv1[8][12]={
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {4,4,4,4,4,4,4,4,4,4,4,4},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2,2}};

    int liv2[8][12]={
      {0,0,0,0,0,0,0,0,0,0,0,0},
      {2,1,2,1,2,1,1,2,1,2,1,2},
      {0,0,0,0,0,0,0,0,0,0,0,0},
      {4,5,3,5,3,2,2,3,5,3,5,4},
      {0,0,0,0,0,0,0,0,0,0,0,0},
      {1,3,1,5,1,3,3,1,5,1,3,1},
      {0,0,0,0,0,0,0,0,0,0,0,0},
      {0,4,0,4,0,5,5,0,4,0,4,0}};

      // iterator it;
      // it = livelli.begin();
      livelli.push_back(l.creaLivello(liv2));
      livelli.push_back(l.creaLivello(liv1));
    }


    void GestoreGioco::draw(int lvl){

      al_draw_bitmap(bg,0,0,0);
      for(int i=0;i<8;i++){
        for(int j=0;j<12;j++){
          if((livelli.at(lvl))[i][j].getColor()!=0 &&(livelli.at(lvl))[i][j].getLives())
            al_draw_bitmap(blocks.at((livelli.at(lvl))[i][j].getColor()-1),16+(j*64),64+i*32,0);
        }
      }
    }


    void GestoreGioco::collisionControl(Vaus v,int lvl){
        if(b.getX() <= 0 || b.getX() >=800 - 22)
          b.setDx(-b.getDx());
        if(b.getY() <= 0)
            b.setDy(-b.getDy());


        if((b.getY() >= 560-22 && b.getY()<=560-18) && b.getX()>= v.getX() && b.getX() <= v.getX()+104)
          b.setDy(-b.getDy());


       for(int i=0;i<8;i++){
         for(int j=0;j<12;j++){
           if((livelli.at(lvl))[i][j].getLives()!=0)
           if(b.getX()>=16+(j*64)&& b.getX() <=16+(j*64)+64 && b.getY()+22 >= 64+i*32 && b.getY() <= 64+(i*32)+32){
              b.setDy(-b.getDy());
              (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
            }
          }
       }
    }
