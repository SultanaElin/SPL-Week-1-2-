#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>

#define TIME_LIMIT_SECONDS 60
#define ROWS 20
#define COLS 20
#define CELL_SIZE 30

typedef struct {
    int x, y;
} Point;
Point food;
Point snake[50];
int length = 1;
//int length2=2;
int score=0;
char direction = 'r'; // 'r' for right, 'l' for left, 'u' for up, 'd' for down

/*void Logo() {
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    // Display the logo text
    outtextxy(100, 100, "TreatForCObra;)");

    int startX = 250; // Starting x-coordinate for all circles
    int radius = 10;  // Radius of each circle
   // int spacing = 0; // Spacing between circles
    int centerX,centerY=150+0*(2*radius)+radius;
 //   setcolor(YELLOW);
 //   settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    // Display the logo text
       circle(startX-2*radius, centerY, 5);
        floodfill(startX-2*radius, centerY, WHITE);

        circle(startX-radius, centerY, radius);

    for (int i = 0; i < 5; i++) {
         centerX = startX; // Use the same x-coordinate for all circles
         centerY =150+ i * (2 * radius ) + radius; // Calculate y-coordinate for each circle


        circle(centerX, centerY, 5);
        floodfill(centerX, centerY, WHITE);
        //setcolor(YELLOW);
        circle(centerX, centerY, radius);

        // You can also fill the circle with a color using floodfill
   }
    int startY=centerY+radius;
    int x=centerX;

    for (int i = 0; i < 2; i++) {
         centerY=5+startY; // Use the same x-coordinate for all circles
         centerX=x + i * (2 * radius) + radius; // Calculate y-coordinate for each circle


     cleardevice();
           food.x+=50;
           food.y+=50;   circle(centerX, centerY, 5);
        floodfill(centerX, centerY, WHITE);snake[i].x + (CELL_SIZE-3)
        //setcolor(YELLOW);
        circle(centerX, centerY, radius);

        // You can also fill the circle with a color using floodfill
   }

    getch();setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    // Display the logo text
    outtextxy(150, 100, "TreatForCObra;)");
    closegraph();
   // return 0;
}*/

void drawBoldRectangle(int left, int top, int right, int bottom, int borderWidth) {
    for (int i = 0; i < borderWidth; i++) {
        rectangle(left + i, top + i, right - i, bottom - i);
    }
}

void drawSnake() {
    for (int i = 0; i < length; i++) {
        setfillstyle(SOLID_FILL, RED);
        bar(snake[i].x, snake[i].y, snake[i].x + (CELL_SIZE-3), snake[i].y + (CELL_SIZE-3));
         if((snake[i].x+snake[i].x + (CELL_SIZE-3))/2==food.x-15||((snake[i].x+snake[i].x + (CELL_SIZE-3))/2==food.x+15)&&((snake[i].y+snake[i].y+ (CELL_SIZE-3))/2==food.y)||((snake[i].y+snake[i].y+ (CELL_SIZE-3))/2==food.y+15)){
            length++;
            score+=100;
            food.x+=50;
            food.y+=50;

        }
    }
}
void drawFood(){
   srand(123); // Use a fixed seed for consistent results

    int maxX = getmaxx();
    int maxY = getmaxy();

    //int radius = 50;
    //food.x = 150;//rand() % (maxX - 2 * 10) + 10; // Random x within screen bounds
   //  food.y = 150;//rand() % (maxY - 2 * 10) + 10; // Random y within screen bounds



    setfillstyle(SOLID_FILL, YELLOW);
    circle(food.x,food.y,10 );
    floodfill(food.x,food.y, WHITE);  // Fill the circle with the current fill style





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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
   // Logo();
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
     time_t startTime, currentTime;
     time(&startTime);



    // Initialize snake's starting position
    for (int i = 0; i < length; i++) {
        snake[i].x = 50;
        snake[i].y = 50;
    }
  int c;
printf("Do you want to start the game: ");
scanf("%d",&c);
if(c==1){
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

        if(newDirection=='f') break;



           //drawfood()




    }
     time(&currentTime);
        double Time = difftime(currentTime, startTime);

        if (Time >= TIME_LIMIT_SECONDS) {

            break;
        }


    }
    }
    cleardevice();
    int color=COLOR(255,0,255);
    setcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(150, 150, "Congratulations!");
    getch();
    closegraph();

    return 0;
}
