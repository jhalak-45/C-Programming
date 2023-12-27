#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to represent a contact
typedef struct {
    char name[100];
    char phoneNumber[20];
    char email[100];
    char address[200];
} Contact;

// Global variables
Contact phonebook[MAX_CONTACTS];
int numContacts = 0;

// Function to save contacts to a file
void saveContactsToFile() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numContacts; ++i) {
        fprintf(file, "%s,%s,%s,%s\n", phonebook[i].name, phonebook[i].phoneNumber,
                phonebook[i].email, phonebook[i].address);
    }

    fclose(file);
}

// Function to load contacts from a file
void loadContactsFromFile() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }

    numContacts = 0;
    while (fscanf(file, "%99[^,],%19[^,],%99[^,],%199[^\n]", phonebook[numContacts].name,
                  phonebook[numContacts].phoneNumber, phonebook[numContacts].email,
                  phonebook[numContacts].address) == 4) {
        numContacts++;
    }

    fclose(file);
}

// Function to add a contact
void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Error: Maximum number of contacts reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", phonebook[numContacts].name);

    printf("Enter phone number: ");
    scanf(" %[^\n]s", phonebook[numContacts].phoneNumber);

    printf("Enter email: ");
    scanf(" %[^\n]s", phonebook[numContacts].email);

    printf("Enter address: ");
    scanf(" %[^\n]s", phonebook[numContacts].address);

    numContacts++;

    // Save data to file after adding a contact
    saveContactsToFile();

    printf("Contact added successfully.\n");
}

// Function to display all contacts in tabular form
void displayAllContacts() {
    if (numContacts == 0) {
        printf("No contacts in the phonebook.\n");
        return;
    }

    printf("\n===== List of Contacts =====\n");
    printf("| %-30s | %-15s | %-30s | %-40s |\n", "Name", "Phone Number", "Email", "Address");
    printf("|----------------------------|-----------------|----------------------------|------------------------------------------|\n");
    for (int i = 0; i < numContacts; ++i) {
        printf("| %-30s | %-15s | %-30s | %-40s |\n", phonebook[i].name, phonebook[i].phoneNumber,
               phonebook[i].email, phonebook[i].address);
    }
    printf("|----------------------------|-----------------|----------------------------|------------------------------------------|\n");
}

// Function to search for a contact by name
void searchContact() {
    char searchName[100];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("\n===== Contact Information =====\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phoneNumber);
            printf("Email: %s\n", phonebook[i].email);
            printf("Address: %s\n", phonebook[i].address);
            printf("================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to update contact information
void updateContact() {
    char updateName[100];
    printf("Enter the name of the contact to update: ");
    scanf(" %[^\n]s", updateName);

    int found = 0;
    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(phonebook[i].name, updateName) == 0) {
            printf("Enter new phone number: ");
            scanf(" %[^\n]s", phonebook[i].phoneNumber);

            printf("Enter new email: ");
            scanf(" %[^\n]s", phonebook[i].email);

            printf("Enter new address: ");
            scanf(" %[^\n]s", phonebook[i].address);

            // Save data to file after updating a contact
            saveContactsToFile();

            printf("Contact information updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void deleteContact() {
    char deleteName[100];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]s", deleteName);

    int found = 0;
    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            // Shift elements to remove the contact
            for (int j = i; j < numContacts - 1; ++j) {
                phonebook[j] = phonebook[j + 1];
            }

            numContacts--;

            // Save data to file after deleting a contact
            saveContactsToFile();

            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    // Load existing data from file
    loadContactsFromFile();

    int choice;
    do {
        printf("\n===== Phonebook System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAllContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                // Save data to file before exiting
                saveContactsToFile();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');
    } while (choice != 6);

    return 0;
}
