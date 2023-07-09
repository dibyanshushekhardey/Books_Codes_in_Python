#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the bucket
typedef struct Node {
    char name[100];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into a bucket
void insertNode(Node** bucket, const char* name) {
    Node* newNode = createNode(name);
    if (*bucket == NULL) {
        *bucket = newNode;
    } else {
        Node* current = *bucket;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the sorted names
void printNames(Node** bucket, int numBuckets) {
    for (int i = numBuckets - 1; i >= 0; i--) {
        Node* current = bucket[i];
        while (current != NULL) {
            printf("%s\n", current->name);
            current = current->next;
        }
    }
}

// Function to perform bucket sort on the array of names
void bucketSort(char** names, int n) {
    // Determine the maximum length of names
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int length = strlen(names[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }

    // Create buckets
    int numBuckets = maxLength + 1;
    Node** bucket = (Node**)malloc(numBuckets * sizeof(Node*));
    for (int i = 0; i < numBuckets; i++) {
        bucket[i] = NULL;
    }

    // Insert names into respective buckets based on the length of names
    for (int i = 0; i < n; i++) {
        int length = strlen(names[i]);
        insertNode(&bucket[length], names[i]);
    }

    // Print the sorted names
    printNames(bucket, numBuckets);

    // Free allocated memory
    for (int i = 0; i < numBuckets; i++) {
        Node* current = bucket[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(bucket);
}

int main() {
    char* names[] = {"Alice", "John", "Bob", "David", "Cindy", "Emma"};
    int n = sizeof(names) / sizeof(names[0]);

    printf("Original names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    printf("\nSorted names:\n");
    bucketSort(names, n);

    return 0;
}
