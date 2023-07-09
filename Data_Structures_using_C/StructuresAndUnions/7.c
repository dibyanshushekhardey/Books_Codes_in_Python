#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void displayEmployees(struct Employee employees[], int numEmployees) {
    printf("Employee Information:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }
}

void editEmployee(struct Employee employees[], int i) {
    printf("Enter the new details for employee %d:\n", i + 1);

    printf("Enter name: ");
    fgets(employees[i].name, sizeof(employees[i].name), stdin);
    employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter age: ");
    scanf("%d", &employees[i].age);
    getchar(); // Consume the newline character

    printf("Enter salary: ");
    scanf("%f", &employees[i].salary);
    getchar(); // Consume the newline character
}

int main() {
    struct Employee employees[5]; // Assuming there are 5 employees

    // Input employee details
    for (int i = 0; i < 5; i++) {
        printf("Enter details for employee %d:\n", i + 1);

        printf("Enter name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter age: ");
        scanf("%d", &employees[i].age);
        getchar(); // Consume the newline character

        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);
        getchar(); // Consume the newline character

        printf("\n");
    }

    // Display employee information
    displayEmployees(employees, 5);

    // Edit details of the ith employee
    int i;
    printf("Enter the index (1-5) of the employee to edit: ");
    scanf("%d", &i);
    getchar(); // Consume the newline character

    if (i >= 1 && i <= 5) {
        editEmployee(employees, i - 1);

        // Display updated employee information
        printf("\nUpdated Employee Information:\n");
        displayEmployees(employees, 5);
    } else {
        printf("Invalid employee index!\n");
    }

    return 0;
}
