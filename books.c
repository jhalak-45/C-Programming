#include <stdio.h>
#include <stdlib.h>

// Structure to represent a book
struct Book {
char name[100];
char author[100];
float price;
};

// Function to input book details
void inputBookDetails(struct Book *book) {
printf("Enter the book name: ");
scanf("%s", book->name);
printf("Enter the author name: ");
scanf("%s", book->author);
printf("Enter the book price (in Rs.): ");
scanf("%f", &book->price);
}

// Function to write book details to the file
void writeToFile(FILE *file, struct Book *book) {
fprintf(file, "%s,%s,%.2f\n", book->name, book->author, book->price);
}

// Function to read book details from the file and print those with price above Rs.300
void printExpensiveBooks(FILE *file) {
rewind(file); // Move the file pointer to the beginning
printf("\nBooks with price above Rs.300:\n");
struct Book book;
while (fscanf(file, "%[^,],%[^,],%f\n", book.name, book.author, &book.price) == 3) {
if (book.price > 300) {
printf("Name: %s, Price: Rs.%.2f\n", book.name, book.price);
}
}
}

int main() {
FILE *libraryFile;

// Open the file in write mode to input book details
libraryFile = fopen("library.dat", "w");
if (libraryFile == NULL) {
printf("Error opening file for writing.\n");
return 1; // Return with an error code
}

struct Book book;

// Input details for 500 books
for (int i = 0; i < 3; ++i) {
inputBookDetails(&book);
writeToFile(libraryFile, &book);
}

// Close the file after writing
fclose(libraryFile);

// Open the file in read mode to print expensive books
libraryFile = fopen("library.dat", "r");
if (libraryFile == NULL) {
printf("Error opening file for reading.\n");
return 1; // Return with an error code
}

// Print details of expensive books
printExpensiveBooks(libraryFile);

// Close the file after reading
fclose(libraryFile);

return 0;
}
