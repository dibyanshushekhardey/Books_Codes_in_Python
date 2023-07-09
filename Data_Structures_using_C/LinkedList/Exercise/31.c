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

// Function to display the information of employees in the linked list
void displayEmployees(struct Employee* head) {
    struct Employee* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Employee Details:\n");
    while (temp != NULL) {
        printf("Employee ID: %d\n", temp->empId);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Salary: %.2f\n", temp->salary);
        printf("-----------------\n");
        temp = temp->next;
    }
}

// Function to delete an employee node from the linked list
void deleteEmployee(struct Employee** head, int empId) {
    if (*head == NULL) {
        printf("The list is empty. No employee to delete.\n");
        return;
    }

    struct Employee* temp = *head;
    struct Employee* prev = NULL;

    // Check if the first node needs to be deleted
    if (temp != NULL && temp->empId == empId) {
        *head = temp->next;
        free(temp);
        printf("Employee with ID %d deleted.\n", empId);
        return;
    }

    // Traverse the linked list to find the employee to delete
    while (temp != NULL && temp->empId != empId) {
        prev = temp;
        temp = temp->next;
    }

    // If the employee is found, delete the node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
        printf("Employee with ID %d deleted.\n", empId);
    } else {
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

    // Display the information of employees in the linked list
    printf("Before Deletion:\n");
    displayEmployees(head);

    // Prompt for the Employee ID to delete
    int empId;
    printf("Enter the Employee ID to delete: ");
    scanf("%d", &empId);

    // Delete the employee from the linked list
    deleteEmployee(&head, empId);

    // Display the updated information of employees in the linked list
    printf("\nAfter Deletion:\n");
    displayEmployees(head);

    return 0;
}
