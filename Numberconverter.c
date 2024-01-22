#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    long long binaryNumber = 0;
    int remainder, base = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        binaryNumber += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary equivalent: %lld\n", binaryNumber);
}

// Function to convert decimal to octal
void decimalToOctal(int decimal) {
    long long octalNumber = 0;
    int remainder, base = 1;

    while (decimal > 0) {
        remainder = decimal % 8;
        octalNumber += remainder * base;
        decimal /= 8;
        base *= 10;
    }

    printf("Octal equivalent: %lld\n", octalNumber);
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hexadecimalNumber[100];
    int i = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimalNumber[i++] = remainder + '0';
        } else {
            hexadecimalNumber[i++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;
    int choice, sourceBase, targetBase;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Choose source base:\n");
    printf("1. Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &sourceBase);

    printf("Choose target base:\n");
    printf("1. Binary\n");
    printf("2. Octal\n");
    printf("3. Hexadecimal\n");
    printf("Enter your choice: ");
    scanf("%d", &targetBase);

    switch (sourceBase) {
        case 1: // Decimal
            switch (targetBase) {
                case 1: // Binary
                    decimalToBinary(decimalNumber);
                    break;
                case 2: // Octal
                    decimalToOctal(decimalNumber);
                    break;
                case 3: // Hexadecimal
                    decimalToHexadecimal(decimalNumber);
                    break;
                default:
                    printf("Invalid target base choice\n");
            }
            break;
        default:
            printf("Invalid source base choice\n");
    }

    return 0;
}
