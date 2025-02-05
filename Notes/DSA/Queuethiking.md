To implement the `enqueue` operation using an array in C, follow these steps, considering a circular queue approach to efficiently manage space:

### Key Concepts:
1. **Circular Array**: Prevents wasted space by wrapping around indices using modulo operations.
2. **Front and Rear Indices**: Track the start and end of the queue.
3. **Full and Empty Conditions**:
   - **Empty**: `front == -1`
   - **Full**: `(rear + 1) % capacity == front` (when using front/rear without a size variable).

### Implementation Steps:

1. **Define the Queue Structure**:
   ```c
   struct Queue {
       int front, rear;
       int capacity;
       int* array;
   };
   ```

2. **Initialize the Queue**:
   ```c
   struct Queue* createQueue(int capacity) {
       struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
       queue->capacity = capacity;
       queue->front = queue->rear = -1; // Empty initially
       queue->array = (int*)malloc(capacity * sizeof(int));
       return queue;
   }
   ```

3. **Check if Queue is Full**:
   ```c
   int isFull(struct Queue* queue) {
       return (queue->rear + 1) % queue->capacity == queue->front;
   }
   ```

4. **Check if Queue is Empty**:
   ```c
   int isEmpty(struct Queue* queue) {
       return queue->front == -1;
   }
   ```

5. **Enqueue Operation**:
   ```c
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
   ```

### Explanation:
- **Circular Increment**: Using `(rear + 1) % capacity` ensures the rear index wraps around to `0` after reaching the end.
- **Full Check**: The queue is full if the next rear position equals the front, leaving one slot unused to distinguish full from empty.
- **Empty Handling**: When the queue is empty, both front and rear are set to `0` on the first enqueue.

### Example Usage:
```c
int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10); // Enqueued at index 0
    enqueue(queue, 20); // Enqueued at index 1
    enqueue(queue, 30); // Index 2
    enqueue(queue, 40); // Index 3
    enqueue(queue, 50); // Fails if using front/rear without size (capacity-1 elements allowed)

    return 0;
}
```

### Notes:
- **Capacity Management**: This implementation allows `capacity - 1` elements to avoid ambiguity. To use all `capacity` slots, include a `size` variable and check `size == capacity`.
- **Dynamic Resizing**: For a dynamic queue, check capacity and reallocate memory when full, though this is more complex.

By following this logic, you ensure efficient space usage and correct FIFO behavior in your queue implementation.