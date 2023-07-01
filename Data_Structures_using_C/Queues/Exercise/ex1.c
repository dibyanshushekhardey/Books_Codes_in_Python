#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

int size(struct Queue* queue) {
    int count = 0;
    struct Node* current = queue->front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    int numItems = size(&myQueue);
    printf("Number of items in the queue: %d\n", numItems);

    return 0;
}
