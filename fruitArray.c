#include <stdio.h>

int main() {
    // Define an array of fruits
    char *fruits[] = {
        "Apple",
        "Banana",
        "Orange",
        "Grapes",
        "Watermelon",
        "Mango",
        "Strawberry",
        "Pineapple",
        "Kiwi",
        "Blueberry",
        "Apple",
        "Banana",
        "Orange",
        "Grapes",
        "Watermelon",
        "Mango",
        "Strawberry",
        "Pineapple",
        "Kiwi",
        "Blueberry",
        "Apple",
        "Banana",
        "Orange",
        "Grapes",
        "Watermelon",
        "Mango",
        "Strawberry",
        "Pineapple",
        "Kiwi",
        "Blueberry"

    };

    // Calculate the number of fruits in the array
    int numFruits = sizeof(fruits) / sizeof(fruits[0]);

    // Print all the fruits in the array
    printf("List of Fruits:\n");
    for (int i = 0; i < numFruits; ++i) {
        printf("%d . %s\n", i +1, fruits[i]);
        

    }
    return 0;
}
