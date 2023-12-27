#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

// Structure to represent a user
typedef struct {
    char username[50];
    char password[50];
} User;

// Global variables
User users[MAX_USERS];
int numUsers = 0;

// Function to save users to a file
void saveUsersToFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numUsers; ++i) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

// Function to load users from a file
void loadUsersFromFile() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }

    numUsers = 0;
    while (fscanf(file, "%49s %49s", users[numUsers].username, users[numUsers].password) == 2) {
        numUsers++;
    }

    fclose(file);
}

// Function to register a new user
void registerUser() {
    if (numUsers == MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%49s", users[numUsers].username);

    printf("Enter password: ");
    scanf("%49s", users[numUsers].password);

    numUsers++;

    // Save data to file after registering a user
    saveUsersToFile();

    printf("User registered successfully.\n");
}

// Function to authenticate a user
int authenticateUser() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%49s", username);

    printf("Enter password: ");
    scanf("%49s", password);

    for (int i = 0; i < numUsers; ++i) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Authentication successful. Welcome, %s!\n", username);
            return 1; // Authentication successful
        }
    }

    printf("Authentication failed. Invalid username or password.\n");
    return 0; // Authentication failed
}

int main() {
    // Load existing data from file
    loadUsersFromFile();

    int choice;
    do {
        printf("\n===== User Authentication System =====\n");
        printf("1. Register User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                // Save data to file before exiting
                saveUsersToFile();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');
    } while (choice != 3);

    return 0;
}
