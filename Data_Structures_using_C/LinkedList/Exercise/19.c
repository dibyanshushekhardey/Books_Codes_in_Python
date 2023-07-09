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

// Function to interchange the values of the first and last elements,
// second and second last elements, and so on, of a doubly linked list
void interchangeElements(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct Node* first = *head;
    struct Node* last = *head;

    while (last->next != NULL) {
        last = last->next;
    }

    while (first != last && first->prev != last) {
        // Swap the values of the first and last elements
        int temp = first->data;
        first->data = last->data;
        last->data = temp;

        // Move to the next elements
        first = first->next;
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the doubly linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Display the original doubly linked list
    printf("Original List: ");
    displayList(head);

    // Interchange the elements in the doubly linked list
    interchangeElements(&head);

    // Display the modified doubly linked list
    printf("Interchanged List: ");
    displayList(head);

    return 0;
}
