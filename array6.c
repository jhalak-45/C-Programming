#include <stdio.h>

int main() {
    // Initialize variables
    int i;
    double numbers[10], total = 0;

    // Prompt the user to enter ten numbers and store them in the array
    for (i = 0; i < 10; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &numbers[i]);

        // Add the entered number to the total
        total += numbers[i];
    }

    // Calculate and display the average
    double average = total / 10;
    printf("\nThe average of the ten numbers is: %.2lf\n", average);

    return 0;
}
