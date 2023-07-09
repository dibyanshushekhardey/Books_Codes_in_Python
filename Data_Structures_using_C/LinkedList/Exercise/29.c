#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for an employee
struct Employee {
    int empId;
    char name[100];
    int age;
    float salary;
    struct Employee* next;
};

// Function to create a new employee node with the given details
struct Employee* createEmployee(int empId, char name[], int age, float salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    newEmployee->empId = empId;
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to insert an employee node at the end of the linked list
void insertEmployee(struct Employee** head, struct Employee* newEmployee) {
    if (*head == NULL) {
        // If the list is empty, make the new employee node the head
        *head = newEmployee;
    } else {
        // Traverse to the last node
        struct Employee* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new employee node at the end
        temp->next = newEmployee;
    }
}

// Function to display the record of a given employee in the linked list
void displayEmployeeRecord(struct Employee* head, int empId) {
    struct Employee* temp = head;
    bool found = false;

    while (temp != NULL) {
        if (temp->empId == empId) {
            printf("Employee Record:\n");
            printf("Employee ID: %d\n", temp->empId);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Salary: %.2f\n", temp->salary);
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", empId);
    }
}

int main() {
    struct Employee* head = NULL;

    // Create employee nodes and insert them into the linked list
    struct Employee* emp1 = createEmployee(1, "John Doe", 30, 50000.0);
    insertEmployee(&head, emp1);

    struct Employee* emp2 = createEmployee(2, "Jane Smith", 35, 60000.0);
    insertEmployee(&head, emp2);

    struct Employee* emp3 = createEmployee(3, "Mark Johnson", 28, 45000.0);
    insertEmployee(&head, emp3);

    // Display the record of a given employee
    int empId;
    printf("Enter the Employee ID to display the record: ");
    scanf("%d", &empId);
    displayEmployeeRecord(head, empId);

    return 0;
}
