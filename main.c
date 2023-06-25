#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FIELD_LENGTH 20
#define MAX_LINES 1000

struct data {
    char buying[MAX_FIELD_LENGTH];
    char maint[MAX_FIELD_LENGTH];
    char doors[MAX_FIELD_LENGTH];
    char persons[MAX_FIELD_LENGTH];
    char lug_boot[MAX_FIELD_LENGTH];
    char safety[MAX_FIELD_LENGTH];
    char label[MAX_FIELD_LENGTH];
};

struct data cars[MAX_LINES];
int numberOfLines = 0;

void runMenu() {
    int choice;
    do {
        printf("\n*** MENU ***\n");
        printf("1. Predict new Trade\n");
        printf("2. Trade Prediction History\n");
        printf("3. Label new Trades\n");
        printf("4. Prediction Evaluation\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You have selected option 1: Predict new Trade.\n");
                // add code for this option
                break;
            case 2:
                printf("You have selected option 2: Trade Prediction History.\n");
                // add code for this option
                break;
            case 3:
                printf("You have selected option 3: Label new Trades.\n");
                // add code for this option
                break;
            case 4:
                printf("You have selected option 4: Prediction Evaluation.\n");
                // add code for this option
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}

void readDataDotTxt() {
//    struct data cars[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    FILE *fp;
    int j;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("error: failed to open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && numberOfLines < MAX_LINES) {
        j = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                   cars[numberOfLines].buying, cars[numberOfLines].maint, cars[numberOfLines].doors,
                   cars[numberOfLines].persons, cars[numberOfLines].lug_boot, cars[numberOfLines].safety,
                   cars[numberOfLines].label);
        if (j != 7) {
            printf("error: invalid line format\n");
            exit(1);
        }
        numberOfLines++;
    }
    fclose(fp);
}

int main() {
    readDataDotTxt();
    printf("read %d lines from file:\n", numberOfLines);
    for (int j = 0; j < numberOfLines; j++) {
        printf("[LINE%d] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n", j, cars[j].buying,
               cars[j].maint, cars[j].doors, cars[j].persons,
               cars[j].lug_boot, cars[j].safety, cars[j].label);
    }
    return 0;
}

