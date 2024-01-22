#include <stdio.h>

int main()
{
    char barcode[13];
    int digits[11];
    int sum1 = 0, sum2 = 0, total;

    printf("Enter the 12-digit barcode: ");
    scanf("%12s", barcode);

    // Extract the first 11 digits
    for (int i = 0; i < 11; i++)
    {
        digits[i] = barcode[i] - '0';
    }

    for (int i = 0; i <= 10; i += 2)
    {
        sum1 += digits[i];
    }
    for (int i = 1; i <= 10; i += 2)
    {
        sum2 += digits[i];
    }
    total = (sum1 * 3 + sum2) - 1;

    // Compute remainder and subtract from 9
    int remainder = total % 10;
    int validationResult = 9 - remainder;

    // Check if the validation result matches the check digit
    if (validationResult == barcode[11] - '0')
    {
        printf("The barcode is valid.\n");
    }
    else
    {
        printf("The barcode is invalid.\n");
    }

    return 0;
}
