#include <stdio.h>

int main() {
    // Initialize variables
    int i, searchNumber;
    int numbers[10];

    // Prompt the user to enter ten numbers and store them in the array
    printf("Enter ten numbers:\n");
    for (i = 0; i < 10; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Prompt the user to enter the number to search
    printf("Enter the number you want to search: ");
    scanf("%d", &searchNumber);

    // Search for the entered number in the array
    int found = 0; // 0 represents false (not found)
    for (i = 0; i < 10; ++i) {
        if (numbers[i] == searchNumber) {
            found = 1; // 1 represents true (found)
            break;     // Exit the loop since the number is found
        }
    }

    // Display the result based on whether the number is found or not
    if (found) {
        printf("Number Found\n");
    } else {
        printf("Number Not Found\n");
    }

    return 0;
}
