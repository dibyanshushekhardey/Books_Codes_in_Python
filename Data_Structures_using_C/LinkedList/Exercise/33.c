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

// Function to reverse the singly linked list by interchanging the links
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
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

    // Display the original singly linked list
    printf("Original Singly Linked List:\n");
    displayList(head);

    // Reverse the singly linked list
    reverseLinkedList(&head);

    // Display the reversed singly linked list
    printf("\nReversed Singly Linked List:\n");
    displayList(head);

    return 0;
}
