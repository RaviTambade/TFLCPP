#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue* createQueue(int capacity) {

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1; // Empty initially
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}


int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0; // First element
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity; // Move rear circularly
    }
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue.\n", item);
}

int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        // Queue becomes empty after dequeue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

  void display(struct Queue* queue){
    if(queue->front==-1){
        printf("Queue is empty\n");
        return;
    }
    int i=queue->front;
    while(i!=queue->rear){
        printf("%d ", queue->array[i]);
        i=(i+1)%queue->capacity;
    }
    printf("%d\n", queue->array[queue->rear]);
  }