#include "GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
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
            al_draw_bitmap(blocks.at((livelli.at(lvl))[i][j].getColor()-1),border+(j*blockW),blockW+i*blockH,0);//border 12
        }
      }
    }


    void GestoreGioco::collisionControl(Vaus &v,int lvl){
      cancellato=false;
      completato=false;
        if(b.getX() <= 0 || b.getX() >=screenW - ballDim){
          b.setDx(-b.getDx());
        }
        if(b.getY() <= 0){
            b.setDy(-b.getDy());
          }


        if((b.getY() >= 560-ballDim && b.getY()<=560-18) && b.getX()+ballDim>= v.getX() && b.getX() <= v.getX()+paddleW){
          b.setDx((((b.getX()-v.getX())*(6+3))/(paddleW))+(-3));
          b.setDy((6-abs(b.getDx())));
        }


       for(int i=0;i<mHeight;i++){
         for(int j=0;j<mWidth;j++){
           // if(((livelli.at(lvl))[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=border+(j*blockW)&& b.getX() <=border+(j*blockW)+blockW && b.getY()+22 >= blockW+i*blockH && b.getY() <= blockW+(i*blockH)+blockH && !cancellato){
           //   if((livelli.at(lvl))[i][j].getColor()!=5){
           //   (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
           //   livesSum[lvl]-=1;
           //   }
           //   b.setDy(-b.getDy());
           //   cancellato=true;
           //   break;
           // }
           // else if(((livelli.at(lvl))[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+22>=border+(j*blockW)&& b.getX() <=border+(j*blockW)+blockW && b.getY()+22 >= blockW+i*blockH && b.getY() <= blockW+(i*blockH)+blockH && !cancellato){
           //  if((livelli.at(lvl))[i][j].getColor()!=5){
           //    (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
           //    livesSum[lvl]-=1;
           //  }
           //    b.setDx(-b.getDx());
           //    cancellato=true;
           //    break;
           // }

           //RIGHT
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getY()+ballDim>=blockW+i*blockH && b.getY() <=blockW+(i*blockH)+blockH && b.getX()<=border+(j*blockW)+blockW && b.getX()>=border+(j*blockW)+blockW-2  &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
               v.setScore(v.getScore()+scoreIncrement);
             }
             b.setDx(-b.getDx());
             cancellato=true;
             break;
           }

           //LEFT
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getY()+ballDim>=blockW+i*blockH && b.getY() <=blockW+(i*blockH)+blockH && b.getX()+ballDim>=border+(j*blockW) && b.getX()+ballDim<=border+(j*blockW)+2  &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
               v.setScore(v.getScore()+scoreIncrement);
             }
             b.setDx(-b.getDx());
             cancellato=true;
             break;
           }
           //TOP
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+ballDim>=border+(j*blockW)&& b.getX() <=border+(j*blockW)+blockW && b.getY()+ballDim>=blockW+i*blockH && b.getY()+ballDim<=blockW+i*blockH+2 &&!cancellato){
             if((livelli.at(lvl))[i][j].getColor()!=5){
               (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
               livesSum[lvl]-=1;
               v.setScore(v.getScore()+scoreIncrement);
               }
               b.setDy(-b.getDy());
               cancellato=true;
               break;
             }
             //DOWN
           if((livelli.at(lvl)[i][j].getLives()!=0 || livelli.at(lvl)[i][j].getColor()==5) && b.getX()+ballDim>=border+(j*blockW)&& b.getX() <=border+(j*blockW)+blockW && b.getY()<=blockW+(i*blockH)+blockH && b.getY()+ballDim>=blockW+i*blockH-2 &&!cancellato){
            if((livelli.at(lvl))[i][j].getColor()!=5){
              (livelli.at(lvl))[i][j].setLives((livelli.at(lvl)[i][j].getLives())-1);
              livesSum[lvl]-=1;
              v.setScore(v.getScore()+scoreIncrement);
              }
             b.setDy(-b.getDy());
             cancellato=true;
             break;
           }


               }
             }
       if(livesSum[lvl]==0)
       completato=true;

       cout<<v.getScore()<<endl;
       // cout<<cancellato<<endl;
       // for(int i=0;i<8;i++){
       //   for(int j=0;j<12;j++){
       //      livesSum+=(livelli.at(lvl))[i][j].getLives();
       //    }
       // }

    }
    GestoreGioco::~GestoreGioco(){
      al_destroy_bitmap(paddle);
      al_destroy_bitmap(bg);
      for(int i=0;i<5;i++){
        al_destroy_bitmap(blocks[i]);
      }
      for(int i=0;i<2;i++){
        al_destroy_bitmap(enemies[i]);
      }
    }

    void GestoreGioco::enemyMove(Enemy* &en,int lvl){
        al_draw_bitmap(enemies.at(lvl%2),en->getX(),en->getY(),0);
        // al_flip_display();

        if(en->getX() <= 0 || en->getX() >=screenW - enemyW){
          en->setDx(-en->getDx());
        }
        if(en->getY() <= 0){
            en->setDy(-en->getDy());
          }
          if(en->getY()+scoreIncrement4 >= 500){
              en->setDy(-en->getDy());
            }

        if(b.getX()<=en->getX()+enemyW && b.getX()+ballDim>=en->getX() && b.getY()+ballDim>=en->getY() && b.getY()<=en->getY()+enemyW){
          b.setDx(rand() % 6+1);
          b.setDy(rand() % 6+1);
          en->setAlive(false);
        }
    }
    GestoreGioco::GestoreGioco(const GestoreGioco& g){

    }
