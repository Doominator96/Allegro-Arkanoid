#include "GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
  dx=1;
  dy=1;
  numLivelli=2;
  Livello l;
  // livesSum=0;
  srand(time(NULL));
  if (!al_init())
  cerr << "No Allegro" << endl;

  blocks.push_back(al_load_bitmap("red.png"));
  blocks.push_back(al_load_bitmap("blue.png"));
  blocks.push_back(al_load_bitmap("green.png"));
  blocks.push_back(al_load_bitmap("silver.png"));
  blocks.push_back(al_load_bitmap("gold.png"));
  enemies.push_back(al_load_bitmap("enemy1.png"));
  enemies.push_back(al_load_bitmap("enemy2.png"));
  bg = al_load_bitmap("back.jpg");
  for (unsigned i = 0; i<blocks.size(); i++)
  if (!blocks[i])
  cerr << "No Blocks bitmap " << endl;

  paddle=al_load_bitmap("paddle.png");
  ball=al_load_bitmap("ball.png");

  int liv0[8][12]={
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,0,0,0,0,0,0,0,0,2,0},
    {0,2,0,0,0,0,0,0,0,0,2,0},
    {0,2,0,0,0,0,0,0,0,0,2,0},
    {0,2,0,0,0,0,0,0,0,0,2,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0}};
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
      Block** l1=l.creaLivello(liv0);
      Block** l2=l.creaLivello(liv1);
      Block** l3=l.creaLivello(liv2);
      livelli.push_back(l2);
      livelli.push_back(l3);
      livelli.push_back(l1);
      livesSum[0]=84;
      livesSum[1]=40;
      livesSum[2]=8;
    }


    void GestoreGioco::draw(int lvl){

      al_draw_bitmap(bg,0,0,0);
      for(int i=0;i<8;i++){
        for(int j=0;j<12;j++){
          if((livelli.at(lvl))[i][j].getLives()>0 ||(livelli.at(lvl))[i][j].getColor()==5)
            al_draw_bitmap(blocks.at((livelli.at(lvl))[i][j].getColor()-1),16+(j*64),64+i*32,0);
        }
      }
    }


    void GestoreGioco::collisionControl(Vaus v,int lvl){
      cancellato=false;
      completato=false;
        if(b.getX() <= 0 || b.getX() >=800 - 22){
          b.setDx(-b.getDx());
        }
        if(b.getY() <= 0){
            b.setDy(-b.getDy());
          }


        if((b.getY() >= 560-22 && b.getY()<=560-18) && b.getX()+22>= v.getX() && b.getX() <= v.getX()+104){
          b.setDx((((b.getX()-v.getX())*(6+3))/(104))+(-3));
          b.setDy((6-abs(b.getDx())));
        }


       for(int i=0;i<8;i++){
         for(int j=0;j<12;j++){
           // if(((livelli.at(lvl))[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=16+(j*64)&& b.getX() <=16+(j*64)+64 && b.getY()+22 >= 64+i*32 && b.getY() <= 64+(i*32)+32 && !cancellato){
           //   if((livelli.at(lvl))[i][j].getColor()!=5){
           //   (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
           //   livesSum[lvl]-=1;
           //   }
           //   b.setDy(-b.getDy());
           //   cancellato=true;
           //   break;
           // }
           // else if(((livelli.at(lvl))[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=16+(j*64)&& b.getX() <=16+(j*64)+64 && b.getY()+22 >= 64+i*32 && b.getY() <= 64+(i*32)+32 && !cancellato){
           //  if((livelli.at(lvl))[i][j].getColor()!=5){
           //    (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
           //    livesSum[lvl]-=1;
           //  }
           //    b.setDx(-b.getDx());
           //    cancellato=true;
           //    break;
           // }

           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getY()+22>=64+i*32 && b.getY() <=64+(i*32)+32 && b.getX()<=16+(j*64)+64 && b.getX()>=16+(j*64)+64-2  &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
             }
             b.setDx(-b.getDx());
             cancellato=true;
             break;
           }

           //LEFT
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getY()+22>=64+i*32 && b.getY() <=64+(i*32)+32 && b.getX()+22>=16+(j*64) && b.getX()+22<=16+(j*64)+2  &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
             }
             b.setDx(-b.getDx());
             cancellato=true;
             break;
           }
           //TOP
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=16+(j*64)&& b.getX() <=16+(j*64)+64 && b.getY()+22>=64+i*32 && b.getY()+22<=64+i*32+2 &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
               }
               b.setDy(-b.getDy());
               cancellato=true;
               break;
             }
             //DOWN
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=16+(j*64)&& b.getX() <=16+(j*64)+64 && b.getY()<=64+(i*32)+32 && b.getY()+22>=64+i*32-2 &&!cancellato){
            if((livelli.at(lvl))[i][j].getColor()!=5){
              (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
              livesSum[lvl]-=1;
              }
             b.setDy(-b.getDy());
             cancellato=true;
             break;
           }

           //RIGHT

               }
             }
       if(livesSum[lvl]==0)
       completato=true;

       cout<<livesSum[lvl]<<endl;
       // cout<<cancellato<<endl;
       // for(int i=0;i<8;i++){
       //   for(int j=0;j<12;j++){
       //      livesSum+=(livelli.at(lvl))[i][j].getLives();
       //    }
       // }

    }
    void GestoreGioco::enemyMove(Enemy* &en,int lvl){
        al_draw_bitmap(enemies.at(lvl%2),en->getX(),en->getY(),0);
        // al_flip_display();

        if(en->getX() <= 0 || en->getX() >=800 - 69){
          en->setDx(-en->getDx());
        }
        if(en->getY() <= 0){
            en->setDy(-en->getDy());
          }
          if(en->getY()+104 >= 500){
              en->setDy(-en->getDy());
            }

        if(b.getX()<=en->getX()+69 && b.getX()+22>=en->getX() && b.getY()+22>=en->getY() && b.getY()<=en->getY()+69){
          b.setDx(rand() % 6+1);
          b.setDy(rand() % 6+1);
          en->setAlive(false);
        }
    }
