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

int numberOfLinesOfData;
int numberOfLinesOfAddedData;
int numberOfLinesOfHistory;
int Counter = 0;

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

void readDataFrom(char *address) {
    char line[MAX_LINE_LENGTH];
    FILE *fp;
    int j;
    int numberOfLines = 0;

    fp = fopen(address, "r");
    if (fp == NULL) {
        printf("error: failed to open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && Counter < MAX_LINES) {
        j = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                   cars[Counter].buying, cars[Counter].maint, cars[Counter].doors,
                   cars[Counter].persons, cars[Counter].lug_boot, cars[Counter].safety,
                   cars[Counter].label);
        if (j != 7) {
            printf("error: invalid line format\n");
            exit(1);
        }
        Counter++;
        numberOfLines++;
    }
    strcmp(address, "FILES/data.txt") == 0 ? numberOfLinesOfData = numberOfLines : printf("");
    strcmp(address, "FILES/added_data.txt") == 0 ? numberOfLinesOfAddedData = numberOfLines : printf("");
    strcmp(address, "FILES/history.txt") == 0 ? numberOfLinesOfHistory = numberOfLines : printf("");
    fclose(fp);
}

int main() {
    readDataFrom("FILES/data.txt");
    readDataFrom("FILES/added_data.txt");
    printf("numberOfLinesOfData = %d\nnumberOfLinesOfAddedData = %d\n", numberOfLinesOfData, numberOfLinesOfAddedData);
    for (int j = 0; j < numberOfLinesOfData + numberOfLinesOfAddedData; j++) {
        printf("[LINE%d] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n", j + 1, cars[j].buying,
               cars[j].maint, cars[j].doors, cars[j].persons,
               cars[j].lug_boot, cars[j].safety, cars[j].label);
    }

//    runMenu();
    return 0;
}

