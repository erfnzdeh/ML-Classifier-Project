#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>


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

struct Label_Data {
    int buying[4];
    int maint[4];
    int doors[4];
    int persons[3];
    int lug_boot[3];
    int safety[3];
    int all;
};

struct Label_Data Label[4];

void clearScreen() {
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void dataAnalysisInitiate() {
    char line[MAX_LINE_LENGTH];
    char buying[MAX_FIELD_LENGTH];
    char maint[MAX_FIELD_LENGTH];
    char doors[MAX_FIELD_LENGTH];
    char persons[MAX_FIELD_LENGTH];
    char lug_boot[MAX_FIELD_LENGTH];
    char safety[MAX_FIELD_LENGTH];
    char label[MAX_FIELD_LENGTH];
    int buyingNumber = -1;
    int maintNumber = -1;
    int doorsNumber = -1;
    int personsNumber = -1;
    int lug_bootNumber = -1;
    int safetyNumber = -1;
    int labelNumber = -1;

    FILE *fp;
    int j;

    fp = fopen("FILES/data.txt", "r");
    if (fp == NULL) {
        printf("error: failed to open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && Counter < MAX_LINES) {
        j = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                   buying, maint, doors, persons, lug_boot, safety, label);
        if (j != 7) {
            printf("error: invalid line format\n");
            exit(1);
        }

        printf("%s %s %s %s %s %s %s\n", buying, maint, doors, persons, lug_boot, safety, label);

        //buying
        strcmp(buying, "vhigh") == 0 ? buyingNumber = 0 : printf("");
        strcmp(buying, "high") == 0 ? buyingNumber = 1 : printf("");
        strcmp(buying, "med") == 0 ? buyingNumber = 2 : printf("");
        strcmp(buying, "low") == 0 ? buyingNumber = 3 : printf("");

        //maint
        strcmp(maint, "vhigh") == 0 ? maintNumber = 0 : printf("");
        strcmp(maint, "high") == 0 ? maintNumber = 1 : printf("");
        strcmp(maint, "med") == 0 ? maintNumber = 2 : printf("");
        strcmp(maint, "low") == 0 ? maintNumber = 3 : printf("");

        //doors
        strcmp(doors, "2") == 0 ? doorsNumber = 0 : printf("");
        strcmp(doors, "3") == 0 ? doorsNumber = 1 : printf("");
        strcmp(doors, "4") == 0 ? doorsNumber = 2 : printf("");
        strcmp(doors, "5more") == 0 ? doorsNumber = 3 : printf("");

        //persons
        strcmp(persons, "2") == 0 ? personsNumber = 0 : printf("");
        strcmp(persons, "4") == 0 ? personsNumber = 1 : printf("");
        strcmp(persons, "more") == 0 ? personsNumber = 2 : printf("");

        //lug_boot
        strcmp(lug_boot, "small") == 0 ? lug_bootNumber = 0 : printf("");
        strcmp(lug_boot, "med") == 0 ? lug_bootNumber = 1 : printf("");
        strcmp(lug_boot, "big") == 0 ? lug_bootNumber = 2 : printf("");

        //safety
        strcmp(safety, "low") == 0 ? safetyNumber = 0 : printf("");
        strcmp(safety, "med") == 0 ? safetyNumber = 1 : printf("");
        strcmp(safety, "high") == 0 ? safetyNumber = 2 : printf("");

        //label
        strcmp(label, "unacc") == 0 ? labelNumber = 0 : printf("");
        strcmp(label, "acc") == 0 ? labelNumber = 1 : printf("");
        strcmp(label, "good") == 0 ? labelNumber = 2 : printf("");
        strcmp(label, "vgood") == 0 ? labelNumber = 3 : printf("");

        printf("%d %d %d %d %d %d %d\n", buyingNumber, maintNumber, doorsNumber, personsNumber, lug_bootNumber, safetyNumber, labelNumber);

        Label[labelNumber].all++;
        Label[labelNumber].buying[buyingNumber]++;
        Label[labelNumber].doors[doorsNumber]++;
        Label[labelNumber].lug_boot[lug_bootNumber]++;
        Label[labelNumber].maint[maintNumber]++;
        Label[labelNumber].persons[personsNumber]++;
        Label[labelNumber].safety[safetyNumber]++;

    }
    fclose(fp);


    printf("\n");
}

int predictNewTrade() {
    int input_buying;
    int input_maint;
    int input_doors;
    int input_persons;
    int input_lug_boot;
    int input_safety;
    int input_Label;

    printf("1. What's the car's buying price?\n");
    printf("[1] vhigh\n");
    printf("[2] high\n");
    printf("[3] med\n");
    printf("[4] low\n");
    printf("Enter your choice: ");
    scanf("%d", &input_buying);
    if (input_buying != 1 && input_buying != 2 && input_buying != 3 && input_buying != 4) {
        return -1;
    }

    printf("\n2. What's the car's maintenance price?\n");
    printf("[1] vhigh\n");
    printf("[2] high\n");
    printf("[3] med\n");
    printf("[4] low\n");
    printf("Enter your choice: ");
    scanf("%d", &input_maint);
    if (input_maint != 1 && input_maint != 2 && input_maint != 3 && input_maint != 4) {
        return -1;
    }

    printf("\n3. How many doors does the car have?\n");
    printf("[1] 2\n");
    printf("[2] 3\n");
    printf("[3] 4\n");
    printf("[4] more!\n");
    printf("Enter your choice: ");
    scanf("%d", &input_doors);
    if (input_doors != 1 && input_doors != 2 && input_doors != 3 && input_doors != 4) {
        return -1;
    }

    printf("\n4. How many persons can the car fit in?\n");
    printf("[1] 2\n");
    printf("[2] 4\n");
    printf("[3] more\n");
    printf("Enter your choice: ");
    scanf("%d", &input_persons);
    if (input_persons != 1 && input_persons != 2 && input_persons != 3) {
        return -1;
    }

    printf("\n5. How big is the car's trunk?\n");
    printf("[1] small\n");
    printf("[2] med\n");
    printf("[3] big\n");
    printf("Enter your choice: ");
    scanf("%d", &input_lug_boot);
    if (input_lug_boot != 1 && input_lug_boot != 2 && input_lug_boot != 3) {
        return -1;
    }

    printf("\n6. How safe is the car?\n");
    printf("[1] low\n");
    printf("[3] med\n");
    printf("[4] high\n");
    printf("Enter your choice: ");
    scanf("%d", &input_safety);
    if (input_safety != 1 && input_safety != 2 && input_safety != 3) {
        return -1;
    }
    printf("\n");

    dataAnalysisInitiate();

    return 1;
}

void runMenu();

void readDataFrom(char *address);

int main() {
//    readDataFrom("FILES/data.txt");
//    readDataFrom("FILES/added_data.txt");
//    printf("numberOfLinesOfData = %d\nnumberOfLinesOfAddedData = %d\n", numberOfLinesOfData, numberOfLinesOfAddedData);
//    for (int j = 0; j < numberOfLinesOfData + numberOfLinesOfAddedData; j++) {
//        printf("[LINE%d] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n", j + 1, cars[j].buying,
//               cars[j].maint, cars[j].doors, cars[j].persons,
//               cars[j].lug_boot, cars[j].safety, cars[j].label);
//    }
//    runMenu();
    dataAnalysisInitiate();
    return 0;
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

void runMenu() {
    int choice;
    do {
        printf("*** MENU ***\n");
        printf("1. Predict new Trade\n");
        printf("2. Trade Prediction History\n");
        printf("3. Label new Trades\n");
        printf("4. Prediction Evaluation\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1:
                printf("You have selected option 1: Predict new Trade.\n");
                predictNewTrade() == -1 ? printf("error! invalid input!\n") : printf("successful!\n");
                printf("Press Any Key to Continue to Menu...\n");
                _getch();
                clearScreen();
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

