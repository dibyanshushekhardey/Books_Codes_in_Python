#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the singly linked list
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

// Function to insert a node at the beginning of the singly linked list
void insertAtBeginning(struct Node** head, struct Node* newNode) {
    newNode->next = *head;
    *head = newNode;
}

// Function to check if the singly linked list is sorted
int isSorted(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, it is considered sorted
        return 1;
    }

    struct Node* current = head;

    while (current->next != NULL) {
        if (current->data > current->next->data) {
            // If any element is greater than the next element, the list is not sorted
            return 0;
        }
        current = current->next;
    }

    // If all elements are in non-decreasing order, the list is sorted
    return 1;
}

// Function to display the singly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create nodes and insert them at the beginning of the singly linked list
    insertAtBeginning(&head, createNode(10));
    insertAtBeginning(&head, createNode(20));
    insertAtBeginning(&head, createNode(30));
    insertAtBeginning(&head, createNode(40));
    insertAtBeginning(&head, createNode(50));

    // Display the singly linked list
    printf("Original Singly Linked List:\n");
    displayList(head);

    // Check if the singly linked list is sorted
    int sorted = isSorted(head);

    if (sorted) {
        printf("\nThe list is sorted.\n");
    } else {
        printf("\nThe list is not sorted.\n");
    }

    return 0;
}
