# include "Livello.h"
Livello::Livello(){
  mWidth=12;
  mHeight=8;
}
Block** Livello::creaLivello(int M[8][12]){
  livello=new Block*[mHeight];
  for(int i=0;i<mHeight;i++)
    livello[i]=new Block[mWidth];

  for(int i=0;i<mHeight;i++)
      for(int j=0;j<mWidth;j++){
        if(M[i][j]==0){
          Block b(0,0);
          livello[i][j]=b;
          }
        else if(M[i][j]==1){
          Block b(1,1);
          livello[i][j]=b;
          }
        else if(M[i][j]==2){
          Block b(2,1);
          livello[i][j]=b;
          }
        else if(M[i][j]==3){
          Block b(3,1);
          livello[i][j]=b;
          }
        else if(M[i][j]==4){
          Block b(4,2);
          livello[i][j]=b;
          }
        else if(M[i][j]==5){
          Block b(5,0);
          livello[i][j]=b;
       }
      }
  // Block b;
  // for(int i=0;i<8;i++)
  // for(int j=0;j<12;j++)
  //   livello[i][j]=b;
  return livello;
}
Livello::~Livello(){
  for(int i=0;i<mHeight;i++)
    delete [] livello[i];

  delete [] livello;
}
Livello::Livello(const Livello &l){
  mHeight=l.mHeight;
  mWidth=l.mWidth;
  livello=new Block*[mHeight];
  for(int i=0;i<mHeight;i++)
    livello[i]=new Block[mWidth];

  for(int i=0;i<mHeight;i++)
    for(int j=0;j<mWidth;j++)
        livello[i][j]=l.livello[i][j];
}
Livello& Livello::operator=(const Livello& l){
  if(this!= &l){
    for(int i=0;i<mHeight;i++)
        delete[] livello[i];
    delete[] livello;
    mHeight=l.mHeight;
    mWidth=l.mWidth;

    livello=new Block*[mHeight];
    for(int i=0;i<mHeight;i++)
      livello[i]=new Block[mWidth];

      for(int i=0;i<mHeight;i++)
        for(int j=0;j<mWidth;j++)
            livello[i][j]=l.livello[i][j];
  }
  return *this;
}
