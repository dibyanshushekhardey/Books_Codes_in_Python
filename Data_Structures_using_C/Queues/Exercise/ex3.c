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

void enqueueFront(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->front == 0) {
        queue->front = MAX_SIZE - 1;
    } else {
        queue->front--;
    }

    queue->items[queue->front] = data;
}

void enqueueRear(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = data;
}

int dequeueFront(struct Queue* queue) {
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

int dequeueRear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->items[queue->rear];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->rear == 0) {
        queue->rear = MAX_SIZE - 1;
    } else {
        queue->rear--;
    }

    return data;
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueueFront(&myQueue, 10);
    enqueueRear(&myQueue, 20);
    enqueueFront(&myQueue, 30);
    enqueueRear(&myQueue, 40);

    printf("Values in the queue (Front to Rear):\n");
    while (!isEmpty(&myQueue)) {
        int value = dequeueFront(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    enqueueFront(&myQueue, 50);
    enqueueRear(&myQueue, 60);
    enqueueFront(&myQueue, 70);
    enqueueRear(&myQueue, 80);

    printf("Values in the queue (Rear to Front):\n");
    while (!isEmpty(&myQueue)) {
        int value = dequeueRear(&myQueue);
        printf("%d ", value);
    }
    printf("\n");

    return 0;
}
