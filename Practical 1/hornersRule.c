#include <stdio.h>
#include <math.h>

int main() {
    // Assume x is a variable
    double x,result;

    // Get user input for the value of x
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the expression
    result = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;

    // Display the result
    printf("Result is: %.2lf\n",result);

    return 0;
}
