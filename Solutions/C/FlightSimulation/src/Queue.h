#include "flight.h"

struct Queue {
    int front, rear;
    int capacity;
    struct Flight * flights;
};

struct Queue* createQueue(int capacity);
void enqueue(struct Queue *queue, struct Flight  flight);
struct Flight dequeue(struct Queue* queue);
void display(struct Queue* queue);