#include "queue.h"
#include <stdio.h>

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10); // Enqueued at index 0
    enqueue(queue, 20); // Enqueued at index 1
    enqueue(queue, 30); // Index 2
    enqueue(queue, 40); // Index 3
    enqueue(queue, 50); // Fails if using front/rear without size (capacity-1 elements allowed)

    display(queue);
    int data=dequeue(queue);
    printf("Dequeued: %d\n", data);
    data=dequeue(queue);
    printf("Dequeued: %d\n", data);
    display(queue);
    return 0;
}