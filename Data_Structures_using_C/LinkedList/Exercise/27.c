#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
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

// Function to insert a node at the end of the circular linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse to the last node
        struct Node* temp = (*head)->next;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to count the number of non-zero values in the circular linked list
int countNonZeroValues(struct Node* head) {
    int count = 0;

    if (head == NULL) {
        return count;
    }

    struct Node* temp = head;

    do {
        if (temp->data != 0) {
            count++;
        }
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertNode(&head, 0);
    insertNode(&head, 2);
    insertNode(&head, 0);
    insertNode(&head, 4);
    insertNode(&head, 0);

    // Display the original circular linked list
    printf("Original List: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");

    // Count the number of non-zero values in the circular linked list
    int nonZeroCount = countNonZeroValues(head);

    printf("Number of Non-Zero Values: %d\n", nonZeroCount);

    return 0;
}
