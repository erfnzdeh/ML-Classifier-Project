#include <stdio.h>

int main() {
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

    return 0;
}