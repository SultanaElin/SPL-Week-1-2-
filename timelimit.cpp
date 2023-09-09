#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIME_LIMIT_SECONDS 10

int main() {
    time_t startTime, currentTime;
    time(&startTime);

    printf("Welcome to the Time-Limited Game!\n");

    while (1) {
        time(&currentTime);
        double Time = difftime(currentTime, startTime);

        if (elapsedTime >= TIME_LIMIT_SECONDS) {
            printf("Time's up! Game over.\n");
            break;
        }

        // Your game logic goes here
        printf("Time left: %.1f seconds\n", TIME_LIMIT_SECONDS - elapsedTime);

        // Introduce a delay to control the loop's iteration speed
        usleep(500000); // Sleep for 500 milliseconds
    }

    printf("Thanks for playing!\n");

    return 0;
}
