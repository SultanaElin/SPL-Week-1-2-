#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void Logo() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int redValue = 255; // Full intensity red
    int greenValue = 0;
    int blueValue = 0;

    int color = COLOR(redValue, greenValue, blueValue);
    setcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(75, 75, "TreatForCObra;)");
    color = COLOR(0, 255, 0);
    setcolor(color);
    outtextxy(0, 100,"Cobra is the most poisonous ");
    outtextxy(0,125,"snake in Bangladesh");
    color = COLOR(255,255,0);
    setcolor(color);
    outtextxy(75,150,"So,be careful!");
    outtextxy(75,175,"Cobra is behind you....");



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

        // You can also fill the circle with a color using floodfill
   }

    getch();
    closegraph();
    return 0;
}
