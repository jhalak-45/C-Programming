#include <stdio.h>

int main() {
    int amount, notes20, notes10, notes5, notes1;

    // Input the total amount
    printf("Enter the total amount: ");
    scanf("%d", &amount);

    // Calculate the number of each type of note
    notes20 = amount / 20;
    amount = amount % 20;

    notes10 = amount / 10;
    amount = amount % 10;

    notes5 = amount / 5;
    amount = amount % 5;

    notes1 = amount;

    // Display the results
    printf("Number of Rs.20 notes: %d\n", notes20);
    printf("Number of Rs.10 notes: %d\n", notes10);
    printf("Number of Rs.5 notes: %d\n", notes5);
    printf("Number of Rs.1 notes: %d\n", notes1);

    return 0;
}
