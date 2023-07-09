#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    float data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, float data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%.2f ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to calculate the sum of the numbers in the linked list
float calculateSum(struct Node* head) {
    float sum = 0.0;
    struct Node* temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

// Function to calculate the mean of the numbers in the linked list
float calculateMean(struct Node* head) {
    float sum = calculateSum(head);
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return sum / count;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 1.5);
    insertNode(&head, 2.7);
    insertNode(&head, 3.8);
    insertNode(&head, 4.2);
    insertNode(&head, 5.1);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Calculate the sum and mean of the numbers in the linked list
    float sum = calculateSum(head);
    float mean = calculateMean(head);

    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);

    return 0;
}
