#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
};

// Function to display the menu
void displayMenu() {
    printf("\n===== Library Management System =====\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
}

// Function to add a book to the system
void addBook(struct Book books[], int *numBooks) {
    if (*numBooks == MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }

    struct Book newBook;
    newBook.id = *numBooks + 1;

    printf("Enter book title: ");
    scanf(" %[^\n]s", newBook.title);

    printf("Enter author name: ");
    scanf(" %[^\n]s", newBook.author);

    printf("Enter quantity: ");
    scanf("%d", &newBook.quantity);

    books[*numBooks] = newBook;
    *numBooks += 1;

    printf("Book added successfully.\n");
}

// Function to display all books in the system
void displayBooks(struct Book books[], int numBooks) {
    if (numBooks == 0) {
        printf("No books in the system.\n");
        return;
    }

    printf("\n===== List of Books =====\n");
    for (int i = 0; i < numBooks; ++i) {
        printf("ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Quantity: %d\n", books[i].quantity);
        printf("------------------------\n");
    }
}

// Function to search for a book by title
void searchBook(struct Book books[], int numBooks) {
    char searchTitle[100];
    printf("Enter the title to search: ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; ++i) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("\n===== Book Found =====\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].quantity);
            printf("------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to save books to a file
void saveBooksToFile(struct Book books[], int numBooks) {
    FILE *file = fopen("library_data.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numBooks; ++i) {
        fprintf(file, "%d,%s,%s,%d\n", books[i].id, books[i].title, books[i].author, books[i].quantity);
    }

    fclose(file);
}

// Function to load books from a file
void loadBooksFromFile(struct Book books[], int *numBooks) {
    FILE *file = fopen("library_data.txt", "r");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }

    *numBooks = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d\n", &books[*numBooks].id, books[*numBooks].title,
                  books[*numBooks].author, &books[*numBooks].quantity) == 4) {
        (*numBooks)++;
    }

    fclose(file);
}

int main() {
    struct Book books[MAX_BOOKS];
    int numBooks = 0;

    // Load existing data from file
    loadBooksFromFile(books, &numBooks);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                displayBooks(books, numBooks);
                break;
            case 3:
                searchBook(books, numBooks);
                break;
            case 4:
                // Save data to file before exiting
                saveBooksToFile(books, numBooks);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
