#include <stdio.h>
#include <math.h>

int main() {
    // Assume x is a variable
    double x;

    // Get user input for the value of x
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the expression
    double result = 3 *x*x*x*x*x + 2 *x*x*x*x - 5 *x*x*x - x*x + 7 * x - 6;

    // Display the result
    printf("Result of the expression  is: %.2lf\n",result);

    return 0;
}
