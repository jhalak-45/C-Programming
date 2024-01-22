#include <stdio.h>
#include <math.h>

double computePolynomial(double x) {
return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}

int main() {
double x;
printf("Enter a value for x: ");
scanf("%lf", &x);
printf("Result of polynomial: %.2f\n", computePolynomial(x));

return 0;
}
