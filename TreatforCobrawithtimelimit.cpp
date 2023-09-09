#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>
#include <unistd.h>

#define TIME_LIMIT_SECONDS 60

#define ROWS 20
#define COLS 20
#define CELL_SIZE 30
#define MAX_RECORDS 10

//LOGO
void logo();
//USER
void user();
//BOX
void drawBoldRectangle(int left, int top, int right, int bottom, int borderWidth);
//SNAKE
void drawSnake();
void moveSnake();
//FOOD
void drawFood();
void foodrand();



 int game=0;
//User

 typedef struct {
    char playerName[50];
    int score;
 } Record;
  Record records[MAX_RECORDS];
  int numofplayer=-1;


//Snake and food
 typedef struct {
    int x, y;
 } Point;

  Point snake[50];
  int length = 1;
  Point food;
char direction = 'r'; // 'r' for right, 'l' for left, 'u' for up, 'd' for down


//logo
  void Logo() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int redValue = 255;
    int greenValue = 0;
    int blueValue = 0;

    int color = COLOR(redValue, greenValue, blueValue);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(color);
    outtextxy(0, 75, "\"Treat");
    color=COLOR(0,255,0);
    setcolor(color);
    outtextxy(150,75,"For");
    color=COLOR(0,0,255);
    setcolor(color);
    outtextxy(225,75,"CObra;)\"");
    color = COLOR(255, 0, 255);
    setcolor(color);
    outtextxy(0, 100," This cobra is ");
    color=COLOR(255,255,255);
    setcolor(color);
    outtextxy(0,125,"   very Hungry");
    color = COLOR(255,255,0);
    setcolor(color);
    outtextxy(75,325,"So,be careful!");
    color=COLOR(0,255,255);
    setcolor(color);
    outtextxy(75,350," Cobra is behind you....");



    int startX = 250; // Starting x-coordinate for all circles
    int radius = 10;  // Radius of each circle

    int centerX,centerY=200+0*(2*radius)+radius;
        setcolor(color);
        circle(startX-2*radius, centerY, 5);
        floodfill(startX-2*radius, centerY, color);
        color=COLOR(255,0,0);
        setcolor(color);
        circle(startX-radius, centerY, radius);

    for (int i = 0; i < 5; i++) {
         centerX = startX; // Use the same x-coordinate for all circles
         centerY =200+ i * (2 * radius ) + radius; // Calculate y-coordinate for each circle

        setcolor(color);
        circle(centerX, centerY, 5);
        floodfill(centerX, centerY, color);
        color = COLOR(255,0, 0);
        setcolor(color);
        circle(centerX, centerY, radius);

        // You can also fill the circle with a color using floodfill
   }
    int startY=centerY+radius;
    int x=centerX;

    for (int i = 0; i < 3; i++) {
         centerY=5+startY; // Use the same x-coordinate for all circles
         centerX=x + i * (2 * radius) + radius; // Calculate y-coordinate for each circle

       // setcolor(color);
        circle(centerX, centerY, 5);
        floodfill(centerX, centerY, color);
        color=COLOR(255,0,0);
       // setcolor(color);
        circle(centerX, centerY, radius);

   }

    getch();
    closegraph();
  }


//User
  void user(){
  numofplayer++;
  printf("Enter your name: ");
  scanf("%s", records[numofplayer].playerName);
  }


//Box
  void drawBoldRectangle(int left, int top, int right, int bottom, int borderWidth) {
    for (int i = 0; i < 5; i++) {


      rectangle(left + i, top + i, right - i, bottom - i);
      }
   /* for (int i = 0; i < 50; i=i+10) {
setfillstyle(SOLID_FILL, YELLOW);
      setcolor(BLUE);
      rectangle(left + i, top + i, right - i, bottom - i);
      }
    for(int i=50;i<100;i=i+10){
        setcolor(YELLOW);
        rectangle(left+i,top+i,right-i,bottom-i);
    }
     for(int i=100;i<150;i=i+10){
        setcolor(GREEN);
        rectangle(left+i,top+i,right-i,bottom-i);
    }
     for(int i=150;i<200;i=i+10){
        setcolor(WHITE);
        rectangle(left+i,top+i,right-i,bottom-i);
    }
    for(int i=200;i<250;i=i+10){
      int color=COLOR(255,0,255);
      setcolor(color);
      rectangle(left+i,top+i,right-i,bottom-i);

    }*/
 }

//Snake
   void drawSnake() {
    for (int i = 0; i < length; i++) {
        setfillstyle(SOLID_FILL, RED);
        bar(snake[i].x, snake[i].y, snake[i].x + (CELL_SIZE-3), snake[i].y + (CELL_SIZE-3));
         if((snake[i].x+snake[i].x + (CELL_SIZE-3))/2>=food.x&&(snake[i].y+snake[i].y+ (CELL_SIZE-3))/2>=food.y){
            length++;
            records[numofplayer].score+=100;
            //cleardevice();
           // delay(100);
           food.x+=50;
           food.y+=50;
           }

        }
     }
   void moveSnake() {

    for (int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    if (direction == 'r') {
        snake[0].x += CELL_SIZE-1;
    } else if (direction == 'l') {
        snake[0].x -= CELL_SIZE-1;
    } else if (direction == 'u') {
        snake[0].y -= CELL_SIZE-1;
    } else if (direction == 'd') {
        snake[0].y += CELL_SIZE-1;
    }
  }


//food
void drawFood(){
   srand(123); // Use a fixed seed for consistent results

    int maxX = getmaxx();
    int maxY = getmaxy();




    setfillstyle(SOLID_FILL, YELLOW);
    circle(food.x,food.y,10 );
    floodfill(food.x,food.y, WHITE);  // Fill the circle with the current fill style





}

  //main
   int main() {
       Logo();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    time_t startTime, currentTime;
    time(&startTime);

     food.x=50;
     food.y=50;

    // Get the dimensions of the graphics window
    int maxX = getmaxx();
    int maxY = getmaxy();

    // Calculate rectangle coordinates and dimensions
    int border = 20;
    int left = border;
    int top = border;
    int right = maxX - border;
    int bottom = maxY - border;

    int borderWidth = 5;




    // Initialize snake's starting position
    for (int i = 0; i < length; i++) {
        snake[i].x = CELL_SIZE * 2;
        snake[i].y = CELL_SIZE * 2;
    }
   for( ; ;){
    user();
    records[numofplayer].score=0;
    printf("%s,Let's begin the game--",records[numofplayer].playerName);

    for( ; ; ) {


        cleardevice();

        drawBoldRectangle(left, top, right, bottom, borderWidth);

        drawSnake();

        drawFood();
        moveSnake();


        delay(100);

        if (direction!='f') {
            char newDirection = getch();
            if (newDirection == 'r' && direction != 'l') {
                direction = 'r';
            } else if (newDirection == 'l' && direction != 'r') {
                direction = 'l';
            } else if (newDirection == 'u' && direction != 'd') {
                direction = 'u';
            } else if (newDirection == 'd' && direction != 'u') {
                direction = 'd';
            }



    }
        time(&currentTime);
        double Time = difftime(currentTime, startTime);

        if (Time >= TIME_LIMIT_SECONDS) {

            break;
        }

    }
    cleardevice();
    int color=COLOR(255,0,255);
    setcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(150, 100, "Time is up!");
    outtextxy(150, 150, "Congratulations!");

    getch();
    closegraph();

    printf("\n%s,your score is:%d\n",records[numofplayer].playerName,records[numofplayer].score);
    char c;
    printf("Do you want to continue?(y/n):");
    scanf(" %c",&c);
    if(c=='n')break;
   }
    return 0;
}
