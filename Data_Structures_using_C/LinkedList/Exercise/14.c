#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, char data) {
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
        printf("%c ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Function to delete the first occurrence of a given character in the linked list
void deleteFirstOccurrence(struct Node** head, char target) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == target) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != target) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to delete the last occurrence of a given character in the linked list
void deleteLastOccurrence(struct Node** head, char target) {
    if (*head == NULL) {
        return;
    }

    struct Node* last = NULL;
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* targetNode = NULL;

    while (current != NULL) {
        if (current->data == target) {
            targetNode = current;
            last = prev;
        }
        prev = current;
        current = current->next;
    }

    if (targetNode == NULL) {
        return;
    }

    if (last == NULL) {
        *head = (*head)->next;
    } else {
        last->next = targetNode->next;
    }

    free(targetNode);
}

// Function to delete all occurrences of a given character in the linked list
void deleteAllOccurrences(struct Node** head, char target) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == target) {
            if (prev == NULL) {
                *head = (*head)->next;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 'A');
    insertNode(&head, 'B');
    insertNode(&head, 'C');
    insertNode(&head, 'D');
    insertNode(&head, 'A');

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Delete the first occurrence of a given character
    char firstTarget = 'B';
    deleteFirstOccurrence(&head, firstTarget);
    printf("After deleting the first occurrence of '%c': ", firstTarget);
    displayList(head);

    // Delete the last occurrence of a given character
    char lastTarget = 'A';
    deleteLastOccurrence(&head, lastTarget);
    printf("After deleting the last occurrence of '%c': ", lastTarget);
    displayList(head);

    // Delete all occurrences of a given character
    char allTarget = 'C';
    deleteAllOccurrences(&head, allTarget);
    printf("After deleting all occurrences of '%c': ", allTarget);
    displayList(head);

    return 0;
}
