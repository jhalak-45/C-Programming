#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to represent an employee
typedef struct {
    int id;
    char name[100];
    char designation[100];
    float salary;
} Employee;

// Global variables
Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// Function to save employees to a file
void saveEmployeesToFile() {
    FILE *file = fopen("employee_data.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numEmployees; ++i) {
        fprintf(file, "%d,%s,%s,%.2f\n", employees[i].id, employees[i].name,
                employees[i].designation, employees[i].salary);
    }

    fclose(file);
}

// Function to load employees from a file
void loadEmployeesFromFile() {
    FILE *file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }

    numEmployees = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%f\n", &employees[numEmployees].id, employees[numEmployees].name,
                  employees[numEmployees].designation, &employees[numEmployees].salary) == 4) {
        numEmployees++;
    }

    fclose(file);
}

// Function to display employee information
void displayEmployee(int index) {
    printf("\n===== Employee Information =====\n");
    printf("ID: %d\n", employees[index].id);
    printf("Name: %s\n", employees[index].name);
    printf("Designation: %s\n", employees[index].designation);
    printf("Salary: %.2f\n", employees[index].salary);
    printf("================================\n");
}

// Function to add an employee to the system
void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Error: Maximum number of employees reached.\n");
        return;
    }

    Employee newEmployee;
    newEmployee.id = numEmployees + 1;

    printf("Enter employee name: ");
    scanf(" %[^\n]s", newEmployee.name);

    printf("Enter designation: ");
    scanf(" %[^\n]s", newEmployee.designation);

    printf("Enter salary: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees] = newEmployee;
    numEmployees++;

    // Save data to file after adding an employee
    saveEmployeesToFile();

    printf("Employee added successfully.\n");
}

// Function to display all employees in the system
void displayAllEmployees() {
    if (numEmployees == 0) {
        printf("No employees in the system.\n");
        return;
    }

    printf("\n===== List of Employees =====\n");
    for (int i = 0; i < numEmployees; ++i) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("------------------------\n");
    }
}

// Function to search for an employee by name
void searchEmployee() {
    char searchName[100];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", searchName);

    int found = 0;
    for (int i = 0; i < numEmployees; ++i) {
        if (strcmp(employees[i].name, searchName) == 0) {
            displayEmployee(i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

// Function to update employee information
void updateEmployee() {
    int updateId;
    printf("Enter the ID of the employee to update: ");
    scanf("%d", &updateId);

    int found = 0;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].id == updateId) {
            printf("Enter new name: ");
            scanf(" %[^\n]s", employees[i].name);

            printf("Enter new designation: ");
            scanf(" %[^\n]s", employees[i].designation);

            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);

            // Save data to file after updating an employee
            saveEmployeesToFile();

            printf("Employee information updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

int main() {
    // Load existing data from file
    loadEmployeesFromFile();

    int choice;
    do {
        printf("\n===== Employee Information System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                // Save data to file before exiting
                saveEmployeesToFile();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
