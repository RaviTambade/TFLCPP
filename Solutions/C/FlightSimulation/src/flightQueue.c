#include "Queue.h"
#include "flight.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue* createQueue(int capacity) {

    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1; // Empty initially
    queue->flights = (struct Flight *)malloc(capacity * sizeof(struct Flight));
    return queue;
}


int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, struct Flight flight) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0; // First element
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity; // Move rear circularly
    }
    queue->flights[queue->rear] = flight;
    printf("%d enqueued to queue.\n", flight.flight_id);
}

struct Flight dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Flight theflight = queue->flights[queue->front];
    if (queue->front == queue->rear) {
        // Queue becomes empty after dequeue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return theflight;
}


void display(struct Queue* queue){
    if(queue->front==-1){
        printf("Queue is empty\n");
        return;
    }
    int i=queue->front;
    while(i!=queue->rear){
        printf("%d ", queue->flights[i]);
        i=(i+1)%queue->capacity;
    }
    printf("%d\n", queue->flights[queue->rear]);
  }