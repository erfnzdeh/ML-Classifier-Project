#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

void clearScreen() {
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

float max(float score, float score1, float score2, float score3) {
    float maximum = score;
    if (score1 > maximum) {
        maximum = score1;
    }
    if (score2 > maximum) {
        maximum = score2;
    }
    if (score3 > maximum) {
        maximum = score3;
    }
    return maximum;
}