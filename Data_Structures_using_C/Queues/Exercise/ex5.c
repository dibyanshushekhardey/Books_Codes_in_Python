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
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1));
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->items[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return data;
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);

    printf("Values in the queue:\n");
    while (!isEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60);
    enqueue(&myQueue, 70);
    enqueue(&myQueue, 80);

    printf("Values in the queue:\n");
    while (!isEmpty(&myQueue)) {
        int value = dequeue(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
