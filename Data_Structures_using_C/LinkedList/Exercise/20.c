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

// Function to make the first element of the linked list as the last element
void moveFirstToLast(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* first = *head;
    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    *head = first->next;
    temp->next = first;
    first->next = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Display the original linked list
    printf("Original List: ");
    displayList(head);

    // Move the first element to the last position
    moveFirstToLast(&head);

    // Display the modified linked list
    printf("Modified List: ");
    displayList(head);

    return 0;
}
