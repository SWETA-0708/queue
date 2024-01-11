#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the front of the queue
void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int removedValue = queue->items[queue->front];
        printf("%d dequeued from the queue.\n", removedValue);

        if (queue->front == queue->rear) {
            // Last element is being dequeued
            initialize(queue);
        } else {
            queue->front++;
        }
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    dequeue(&queue);
    dequeue(&queue);

    enqueue(&queue, 40);

    return 0;
}






