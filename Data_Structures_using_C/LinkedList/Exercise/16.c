#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int digit;
    struct Node* next;
};

// Function to create a new node with the given digit
struct Node* createNode(int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int digit) {
    struct Node* newNode = createNode(digit);

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
        printf("%d ", temp->digit);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter an n-digit number: ");
    scanf("%d", &n);

    // Extract and store each digit in a separate node
    while (n > 0) {
        int digit = n % 10;
        insertNode(&head, digit);
        n /= 10;
    }

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    return 0;
}
