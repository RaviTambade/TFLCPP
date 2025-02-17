struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
void display(struct Queue* queue);