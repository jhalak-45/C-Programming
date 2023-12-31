#include <stdio.h>

int main() {
    // Define the maximum length of the sentence
    #define MAX_LENGTH 100

    // Initialize variables
    char sentence[MAX_LENGTH];

    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Replace 'i' with '1', 's' with '5', and 'o' with '0'
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] == 'i') {
            sentence[i] = '1';
        } else if (sentence[i] == 's') {
            sentence[i] = '5';
        } else if (sentence[i] == 'o') {
            sentence[i] = '0';
        }
    }

    // Display the encoded sentence
    printf("Encoded sentence: %s\n", sentence);

    return 0;
}
