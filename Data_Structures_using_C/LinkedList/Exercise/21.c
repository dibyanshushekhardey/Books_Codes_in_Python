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

// Function to count the number of occurrences of a given value in the linked list
int countOccurrences(struct Node* head, int value) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 2);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Count the occurrences of a value
    int value = 2;
    int occurrences = countOccurrences(head, value);

    printf("Number of occurrences of %d: %d\n", value, occurrences);

    return 0;
}
