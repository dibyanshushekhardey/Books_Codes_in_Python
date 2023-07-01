#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int data) {
    if (isQueueFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->items[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return data;
}

void reverseQueue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return;
    }

    int data = dequeue(queue);

    reverseQueue(queue);

    enqueue(queue, data);
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Original queue: ");
    while (!isQueueEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    reverseQueue(&myQueue);

    printf("Reversed queue: ");
    while (!isQueueEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
