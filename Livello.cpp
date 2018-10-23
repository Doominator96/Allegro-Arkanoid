# include "Livello.h"
Livello::Livello(){

}
Block** Livello::creaLivello(int M[8][12]){
  livello=new Block*[8];
  for(int i=0;i<8;i++)
    livello[i]=new Block[12];
    
  for(int i=0;i<8;i++)
      for(int j=0;j<12;j++){
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
