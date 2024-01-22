#include <stdio.h>

int main() {
    int num,reversed=0;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    if (num >= 10 && num <= 99) {
        // Reverse the digits
        reversed = (num % 10) * 10 + (num / 10);
        printf("The reversal is: %d\n", reversed);
    } else {
        printf("Please enter a valid two-digit number.\n");
    }

    return 0;
}
