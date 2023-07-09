#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
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
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to find the minimum value in the linked list
int findMinimum(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return 0;
    }

    int min = head->data;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}

// Function to find the maximum value in the linked list
int findMaximum(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return 0;
    }

    int max = head->data;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 10);
    insertNode(&head, 5);
    insertNode(&head, 7);
    insertNode(&head, 3);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Find the minimum and maximum values
    int min = findMinimum(head);
    int max = findMaximum(head);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
