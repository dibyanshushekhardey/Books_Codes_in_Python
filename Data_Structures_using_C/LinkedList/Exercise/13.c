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

// Function to insert a node at the end of the doubly linked list
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
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
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

// Function to delete the first element of the doubly linked list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    // Traverse to the last node
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Add the deleted node as the last node
    lastNode->next = temp;
    temp->prev = lastNode;
    temp->next = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Delete the first node and add it as the last node
    deleteFirstNode(&head);

    // Display the updated list
    printf("Updated List: ");
    displayList(head);

    return 0;
}
