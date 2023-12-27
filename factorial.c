
/*
*Program to print factroial of any number
*by Jhalak Dhami
*website:jhalakdhami.com.np

*/
#include <stdio.h>

int main() {
    int num, i;
    unsigned long long factorial = 1;

    // Input the number
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0) {
        printf("Sorry,you have entered for negative numbers.\n");
    } else {
        // Calculate factorial using a loop
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }

        // Print the result
        printf("Factorial of %d = %llu\n", num, factorial);
    }

    return 0;
}
