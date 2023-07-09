#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, struct Node* newNode) {
    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Insert the new node at the beginning
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to find the middle node of the doubly linked list
struct Node* findMiddleNode(struct Node* head) {
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    return slowPtr;
}

// Function to move the middle node to the top of the doubly linked list
void moveMiddleNodeToTop(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // If the list is empty or has only one node, no need to move
        return;
    }

    struct Node* middleNode = findMiddleNode(*head);

    if (middleNode == *head) {
        // If the middle node is already the head, no need to move
        return;
    }

    // Remove the middle node from its current position
    middleNode->prev->next = middleNode->next;
    if (middleNode->next != NULL) {
        middleNode->next->prev = middleNode->prev;
    }

    // Move the middle node to the beginning of the list
    middleNode->prev = NULL;
    middleNode->next = *head;
    (*head)->prev = middleNode;
    *head = middleNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create nodes and insert them into the doubly linked list
    insertAtBeginning(&head, createNode(10));
    insertAtBeginning(&head, createNode(20));
    insertAtBeginning(&head, createNode(30));
    insertAtBeginning(&head, createNode(40));
    insertAtBeginning(&head, createNode(50));

    // Display the original doubly linked list
    printf("Original Doubly Linked List:\n");
    displayList(head);

    // Move the middle node to the top of the list
    moveMiddleNodeToTop(&head);

    // Display the modified doubly linked list
    printf("\nAfter Moving Middle Node to Top:\n");
    displayList(head);

    return 0;
}
