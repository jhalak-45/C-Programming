#include <stdio.h>

int main() {
    int num,reversed=0;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    if (num >= 100 && num <= 999) {
        // Reverse the digits
        reversed = (num % 10) * 100 + ((num / 10) % 10) * 10 + (num / 100);

        printf("The reversal is: %d\n", reversed);
    } else {
        printf("Please enter a valid three-digit number.\n");
    }

    return 0;
}
