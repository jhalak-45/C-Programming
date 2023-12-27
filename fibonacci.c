
/*
*Program to print fibonacci series of number
*by Jhalak Dhami
*website:jhalakdhami.com.np

*/

#include <stdio.h>

int main() {
    int n, i , a = 0, b = 1, c;

    // Input the number of terms
    printf("Enter  number of terms in the Fibonacci series: ");
    scanf("%d", &n);


    // Print the first two terms
    printf("Fibonacci Series: %d, %d, ", a, b);

    // Generate and print the rest of the series
    for (i = 3; i <= n; ++i) {
        c = a + b;
        printf("%d, ", c);

        // Update values for the next iteration
        a = b;
        b = c;
    }


    printf("\n");

    return 0;
}
