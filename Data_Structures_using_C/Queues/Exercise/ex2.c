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

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    return data;
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    int i;
    for (i = 1; i <= 10; i++) {
        enqueue(&myQueue, i * 10);
    }

    printf("Values in the queue:\n");

    while (!isEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }

    printf("\n");

    return 0;
}
