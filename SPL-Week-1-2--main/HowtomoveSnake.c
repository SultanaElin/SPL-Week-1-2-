#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
void setup();
void draw();
void input();
void MakeLogic();
int width=20,heigth=30,flag=0;
char ch;
//for snake
int x,y;
//for fruit
int fruitX,fruitY;
//for score
int score;
//Gameover
int gameover;
void setup(){
  gameover=0;
  x=width/2;
  y=heigth/2;
  fruitX=rand()%20;
  //if Fruit crosses length 20 then fruitX=20 .So,
  if(fruitX==0){
    fruitX=rand()%20;
  }
   fruitY=rand()%30;
  //if Fruit crosses length 30 then fruitX=20 .So,
  if(fruitY==0){
    fruitY=rand()%30;
  }




}
//Boundary
void draw(){
     int i,j;
     system("cls");
     //for clearing before secound call
     for(i=0;i<heigth;i++){
        for(j=0;j<width;j++){
           if(i==0||i==heigth-1||j==0||j==width-1) printf("*");
           else {
            if(i==x&&j==y)
             printf("O");
            else if(i==fruitX&&j==fruitY){
                printf("F");}
            else printf(" ");
           }
        }
        printf("\n");
     }



}






void input(){
     ch='r';
   //r->right,l->left,u->up,d->down
     ch=getch();
    switch(ch){
    case 'r':
        flag=1;
        break;
    case 'l':
        flag=2;
        break;
    case 'd':
        flag=3;
        break;
    case 'u':
        flag=4;
        break;
    case 'x':
        gameover=1;
        break;
    default:
        break;
    }


}
void MakeLogic(){
    switch(flag){
      case 1:
          x++;
          break;
       case 2:
          x--;
          break;
       case 3:
          y--;
          break;
        case 4:
          y++;
          break;
        default:
            break;

    }



}
int main(){
  
   setup();
   //draw();
 while(1){
     

  if(ch!='f'){
   draw();
  input();
  MakeLogic();


  }
  else if(ch=='f') break;

  }
  return 0;

}





