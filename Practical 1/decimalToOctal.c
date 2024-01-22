#include <stdio.h>

int main()
{
    int decimalNumber,octalNumber[100],i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0)
    {
        printf("Please enter a non-negative decimal number.\n");
        return 1; // Exit with an error code
    }
    printf("The octal equivalent is: ");

    if (decimalNumber == 0)
    {
        printf("0");
    }
    else
    {

        while (decimalNumber > 0)
        {
            octalNumber[i] = decimalNumber % 8;
            decimalNumber /= 8;
            i++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", octalNumber[j]);
        }
    }
    return 0;
}
