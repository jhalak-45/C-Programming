#include <stdio.h>

int main() {
    int numbers[4][4];
    int r_sums[4] = {0};
    int c_sums[4] = {0};
    int d_sums[2] = {0};

    // Get user input
    printf("Enter the numbers from 1 to 16 in any order separated by a space:\n");
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }

    // Display the numbers in a 4 by 4 arrangement
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", numbers[i][j]);
            r_sums[i] += numbers[i][j];
            c_sums[j] += numbers[i][j];
            if (i == j) {
                d_sums[0] += numbers[i][j]; // main diagonal
            }
            if (i + j == 3) {
                d_sums[1] += numbers[i][j]; // secondary diagonal
            }
        }
        printf("\n");
    }

    // Display the sums of rows, columns, and diagonals
    printf("\nRow sums: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", r_sums[i]);
    }

    printf("\nColumn sums: ");
    for (int j = 0; j < 4; j++) {
        printf("%d ", c_sums[j]);
    }

    printf("\nDiagonal sums: %d %d\n", d_sums[0], d_sums[1]);

    return 0;
}
