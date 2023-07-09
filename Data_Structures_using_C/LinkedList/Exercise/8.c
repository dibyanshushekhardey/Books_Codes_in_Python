#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly circular linked list
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

// Function to insert a node at the end of the doubly circular linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        // Insert the new node at the end
        struct Node* last = (*head)->prev;

        last->next = newNode;
        newNode->prev = last;

        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Function to display the doubly circular linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Function to sort the doubly circular linked list using bubble sort
void sortList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current;
    struct Node* last = NULL;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                // Swap the values of current and next nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1;
            }

            current = current->next;
        }

        last = current;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly circular linked list
    insertNode(&head, 5);
    insertNode(&head, 3);
    insertNode(&head, 8);
    insertNode(&head, 2);
    insertNode(&head, 6);

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Sort the list
    sortList(head);

    // Display the sorted list
    printf("Sorted List: ");
    displayList(head);

    return 0;
}
