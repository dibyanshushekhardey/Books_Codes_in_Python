#include <stdio.h>
#include <string.h>

struct Employee {
    int empId;
    char name[50];
    char address[100];
    int age;
    float salary;
    char designation[50];
};

int main() {
    struct Employee employees[10]; // Array of 10 employees

    // Read employee data
    for (int i = 0; i < 10; i++) {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("Enter Employee ID: ");
        scanf("%d", &employees[i].empId);
        getchar(); // Consume the newline character

        printf("Enter First Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Middle Name: ");
        fgets(employees[i].name + strlen(employees[i].name), sizeof(employees[i].name) - strlen(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Last Name: ");
        fgets(employees[i].name + strlen(employees[i].name), sizeof(employees[i].name) - strlen(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Address (Area): ");
        fgets(employees[i].address, sizeof(employees[i].address), stdin);
        employees[i].address[strcspn(employees[i].address, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Address (City): ");
        fgets(employees[i].address + strlen(employees[i].address), sizeof(employees[i].address) - strlen(employees[i].address), stdin);
        employees[i].address[strcspn(employees[i].address, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Address (State): ");
        fgets(employees[i].address + strlen(employees[i].address), sizeof(employees[i].address) - strlen(employees[i].address), stdin);
        employees[i].address[strcspn(employees[i].address, "\n")] = '\0'; // Remove trailing newline character

        printf("Enter Age: ");
        scanf("%d", &employees[i].age);
        getchar(); // Consume the newline character

        printf("Enter Salary: ");
        scanf("%f", &employees[i].salary);
        getchar(); // Consume the newline character

        printf("Enter Designation: ");
        fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
        employees[i].designation[strcspn(employees[i].designation, "\n")] = '\0'; // Remove trailing newline character

        printf("\n");
    }

    // Print employee data
    printf("Employee Information:\n");
    for (int i = 0; i < 10; i++) {
        printf("Employee %d\n", i + 1);
        printf("Employee ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Address: %s\n", employees[i].address);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Designation: %s\n", employees[i].designation);
        printf("\n");
    }

    return 0;
}
