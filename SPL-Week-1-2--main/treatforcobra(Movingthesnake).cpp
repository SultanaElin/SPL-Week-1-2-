#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>

#define ROWS 20
#define COLS 20
#define CELL_SIZE 30

typedef struct {
    int x, y;
} Point;

Point snake[50];
int length = 5;
char direction = 'r'; // 'r' for right, 'l' for left, 'u' for up, 'd' for down

void drawGrid() {
   for (int i = 0; i < ROWS; i++) {
       for (int j = 0; j < COLS; j++) {
            int x1 = j*(CELL_SIZE);
            int y1 = i* (CELL_SIZE);
            int x2 = x1 + (CELL_SIZE);
            int y2 = y1 + (CELL_SIZE);

            rectangle(x1, y1, x2, y2);
        }
    }
}

void drawSnake() {
    for (int i = 0; i < length; i++) {
        setfillstyle(SOLID_FILL, BLUE);
        bar(snake[i].x, snake[i].y, snake[i].x + (CELL_SIZE-3), snake[i].y + (CELL_SIZE-3));
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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Initialize snake's starting position
    for (int i = 0; i < length; i++) {
        snake[i].x = CELL_SIZE * 4;
        snake[i].y = CELL_SIZE * 4;
    }

    while (1) {
        cleardevice();
        drawGrid();
        drawSnake();
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

    }

    }
    getch();
    closegraph();

    return 0;
}
