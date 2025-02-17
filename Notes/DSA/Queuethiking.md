***********************************
Okay, so I need to figure out how to implement the enqueue operation using an array in C. Let me start by recalling what a queue is. A queue is a FIFO (First In, First Out) data structure, right? That means the first element added is the first one to be removed. The main operations are enqueue (add to the rear) and dequeue (remove from the front).

Since we're using an array, I have to manage the elements within a fixed-size array. But arrays have static sizes in C, so I need to handle the indices properly. One common approach is to use a circular array to efficiently utilize the space. Wait, why circular? Oh right, because if we just use a linear array, every time we dequeue, the front moves forward, and the space before the front can't be reused, leading to wasted space. A circular array allows us to wrap around when we reach the end, so we can reuse the spaces that have been dequeued.

So, for a circular queue implementation, I'll need a few variables:

- An array to hold the elements.

- A front index pointing to the first element.

- A rear index pointing to the last element.

- Maybe a size variable to keep track of the current number of elements, or alternatively, use the positions of front and rear to determine if the queue is full or empty.

But wait, how do we check if the queue is full or empty? If front and rear are the same, the queue is empty. But if the queue is full, in a circular setup, rear would be just behind front. So, maybe when (rear + 1) % capacity equals front, the queue is full. That way, we can distinguish between a full and an empty queue. Because if we don't have a size variable, just using front and rear, the empty and full conditions can be ambiguous otherwise.

So, for enqueue, the steps would be:

1. Check if the queue is full. If yes, maybe return an error or resize the array (but resizing isn't typical in a fixed-size queue; perhaps just handle overflow).

2. If not full, insert the new element at the rear position.

3. Update the rear index to (rear + 1) % capacity.

Wait, but what if the queue is empty? Then front and rear are both -1 or some invalid index. Maybe we need to handle that case. When inserting the first element, both front and rear should point to 0.

Let me outline the possible structure:

- Define a struct for the queue containing the array, front, rear, and maybe capacity.

- Initialize front and rear to -1 to indicate an empty queue.

- When enqueueing the first element, set front and rear to 0.

- For subsequent elements, increment rear modulo capacity and check if the queue is full before inserting.

But let's think about the enqueue logic step by step. Let's say the queue has a maximum size of MAX. The array is of size MAX. The front starts at 0, rear at -1. Wait, maybe different initializations exist. Alternatively, front and rear start at 0, and we use a size variable to track the number of elements.

Alternatively, using a size variable might make it easier to check if the queue is full (size == MAX) or empty (size == 0). Then front and rear can be managed accordingly.

Hmm. Let me consider different possibilities. Let's say we have:

struct Queue {

int front, rear, size;

unsigned capacity;

int* array;

};

When initializing, front starts at 0, rear is capacity - 1, but that might complicate. Alternatively, front = 0, rear = -1, size = 0, and capacity = MAX.

Then, to enqueue:

Check if size == capacity. If yes, full. Otherwise, increment rear (mod capacity), assign the element to array[rear], and increment size.

Wait, but if rear is initially -1, then after first enqueue, rear becomes ( -1 + 1 ) % capacity = 0. Then array[0] is set. Then next enqueue would increment rear to 1, etc.

Alternatively, if rear starts at 0, then we have to adjust differently.

Wait, maybe it's better to have front pointing to the first element, and rear pointing to the last element. So, when empty, front and rear are both -1. Then, when adding the first element, front and rear become 0. For the next elements, rear increments by 1, but modulo capacity. But if the queue is full, then (rear + 1) % capacity would equal front. Wait, no. Because if the queue is full, then rear is one position behind front. Wait, perhaps the condition for a full queue is (rear + 1) % capacity == front. So, the capacity is actually MAX, but the maximum number of elements is MAX-1. Because one space is left empty to distinguish between full and empty.

So, for example, if the array has MAX elements, the queue can hold up to MAX-1 elements. That way, when front == rear, the queue is empty, and when (rear + 1) % MAX == front, the queue is full.

Hmm, that's a common approach to avoid ambiguity. So, in this case:

Initialize front and rear to 0. Then:

Enqueue:

1. Check if (rear + 1) % capacity == front. If yes, queue is full.

2. Else, insert at array[rear].

3. Then rear = (rear + 1) % capacity.

Wait, but in this case, when inserting the first element, we insert at array[rear], which is 0, then rear becomes (0 +1) % capacity = 1. So front is 0, rear is 1. So the next enqueue would insert at index 1, then rear becomes 2, etc. But when dequeuing, front increments. Wait, but when the queue is full, rear is one position behind front. For example, if capacity is 5, front is 2, rear is 1. Then (1 +1) %5 = 2, which equals front, so the queue is full.

But in this setup, the array can hold capacity-1 elements. So, maybe that's a trade-off. Alternatively, using a size variable might allow us to use all capacity elements. Let's see.

If we have a size variable, then the queue is empty when size == 0, full when size == capacity. Then front and rear can be managed as:

rear = (front + size) % capacity.

Wait, this could be another approach. Let's say front is the index of the first element, and size is the number of elements. Then, the rear index can be calculated as (front + size - 1) % capacity. So, when enqueuing, we need to insert at (front + size) % capacity, then increment size. But this requires maintaining the size variable.

Which approach is better? It depends. Using a size variable might be more straightforward for checking full and empty conditions.

So, struct Queue:

int front; // index of the first element

int size;  // current number of elements

int capacity;

int* array;

Then, enqueue:

if (size == capacity) return error;

int rear = (front + size) % capacity;

array[rear] = new_item;

size++;

This way, we don't need a separate rear variable. The rear is calculated based on front and size. When dequeuing, front becomes (front + 1) % capacity, and size decreases by 1.

This might be simpler. Let's think about the initial state:

front = 0, size = 0. capacity = MAX.

When enqueueing first element: rear = (0 + 0) % MAX = 0. Assign array[0] = element. size becomes 1.

Next enqueue: rear = (0 + 1) % MAX = 1. Assign array[1], size 2.

Dequeue: front becomes (0 + 1) % MAX =1, size 1.

So the next enqueue would be at (1 + 1) % MAX = 2, etc.

This seems manageable. So this approach avoids having to track rear separately. But if we have a separate rear variable, we need to manage it with modulo operations each time.

So perhaps using a size variable is better for clarity and avoiding confusion between front and rear positions.

But the original question is about thinking of the logic for enqueue using an array in C. So regardless of the specific implementation details (with or without size variable), the main logic involves checking if the queue is full, handling the wrap-around using modulo operation, and inserting at the appropriate position.

Wait, but the user mentioned using an array inside. So the queue is implemented with an array, and we have to handle the indices correctly.

Another approach is to use two variables, front and rear. When the queue is empty, front and rear are both -1. When the first element is added, both are set to 0. For subsequent enqueues, rear is incremented, and when it reaches the end, wraps around to 0 if there's space.

But checking if the queue is full would be when (rear + 1) % capacity == front. But this requires that one position is left unused. So the actual number of elements is capacity -1.

Alternatively, using a size variable allows us to use all capacity positions.

So, to outline the steps for enqueue:

If using front and rear indices without a size variable:

1. Check if the queue is full. This is true if (rear + 1) % capacity == front.

- If full, return overflow.

2. If the queue is empty (front == -1), set both front and rear to 0.

3. Else, set rear = (rear + 1) % capacity.

4. Insert the new element at array[rear].

If using a size variable:

1. Check if size == capacity. If yes, overflow.

2. Calculate the insertion index as (front + size) % capacity.

3. Insert the element there.

4. Increment size.

But maybe the first approach (without size variable) is more common. Let's think about code for that.

So, code outline:

struct Queue {

int front, rear;

int capacity;

int* array;

};

// Initialize queue

struct Queue* createQueue(int capacity) {

struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

queue->capacity = capacity;

queue->front = queue->rear = -1;

queue->array = (int*)malloc(capacity * sizeof(int));

return queue;

}

// Enqueue function

void enqueue(struct Queue* queue, int item) {

if ((queue->rear + 1) % queue->capacity == queue->front) {

printf("Queue is full\n");

return;

}

else if (queue->front == -1) { // queue is empty

queue->front = queue->rear = 0;

}

else {

queue->rear = (queue->rear + 1) % queue->capacity;

}

queue->array[queue->rear] = item;

}

But wait, in the full condition, (rear + 1) % capacity equals front. So, when the queue is full, the next position after rear is front, which means we can't insert. So the maximum number of elements is capacity -1.

But if we want to allow all capacity elements to be used, then we need a size variable. Because with size, we can track exactly how many elements are present. So when size == capacity, it's full.

So, using a size variable might be better. Let me think.

Another way: let's have the struct include size.

struct Queue {

int front, rear;

int size;

int capacity;

int* array;

};

Initialize front to 0, size to 0, capacity as MAX. Then rear is (front + size -1) % capacity. But maybe during enqueue, the position to insert is (front + size) % capacity.

Enqueue steps:

if (size == capacity) {

// full

} else {

int pos = (front + size) % capacity;

array[pos] = item;

size++;

}

So here, front remains the same until a dequeue happens. When you dequeue, front increments (mod capacity), and size decreases.

This way, the queue can hold exactly capacity elements. Because size is tracked separately.

For example, capacity = 5. Initially, front=0, size=0. Enqueue 5 elements:

size becomes 1, 2, 3, 4, 5. Then, when size ==5, it's full.

So this approach uses all the capacity. The rear is not stored but calculated as (front + size -1) % capacity.

But during enqueue, the insertion position is (front + size) % capacity.

This seems efficient. But the original question is about the logic for enqueue, so either approach is valid, but maybe the common implementation uses front and rear with modulo and one slot unused.

But since the user is asking about how to think of the logic, the key points are:

- Using a circular array to wrap around the indices when reaching the end.

- Checking for full and empty conditions correctly.

- Updating the rear (or insertion index) correctly with modulo operation.

So, to summarize the steps for enqueue:

1. Check if the queue is full.

- If using front and rear without size: (rear +1) % capacity == front.

- If using size: size == capacity.

2. If full, handle error (e.g., print message, return, etc.)

3. If the queue is empty (size 0 or front == -1):

- Set front and rear to 0 (if using front/rear).

4. Else:

- Increment rear (or calculate insertion index) using modulo to wrap around.

5. Insert the new element at the rear position (or calculated index).

6. If using size, increment size.

Potential issues to consider:

- Handling the initial insertion when the queue is empty.

- Correctly wrapping around the indices using modulo.

- Ensuring that the full condition is checked correctly to prevent overwriting.

Another thing: in C, array indices start at 0, so the modulo operation should be based on the capacity. For example, if capacity is 5, then rear can be 0-4. When rear is 4, (4 +1) %5 =0.

So, the modulo operation ensures that the indices stay within the array bounds.

Examples:

Suppose capacity is 5. Initial front = -1, rear = -1.

Enqueue 10:

Check if queue is full: (rear +1) %5 = (-1 +1) %5 =0. If front is -1, not full. So since queue is empty, set front and rear to 0. array[0] =10.

Enqueue 20:

Check full: (0 +1)%5=1 != front (0). So rear becomes 1. array[1] =20.

Enqueue 30, 40, 50:

rear becomes 2,3,4. Now queue has elements at 0-4. Check if full: (4+1)%5=0. front is 0. So (rear+1) %5 == front → 0 ==0, so queue is full. Can't enqueue more.

Thus, the queue holds 5 elements (indices 0-4), but according to this setup, the maximum number is 4 (since one slot is left unused). Wait, no. Wait, in this case, with capacity 5, the maximum number of elements is 4. Because when rear is 4, (4 +1) %5=0 == front (0), so queue is full. So the array can hold 4 elements. But if we use a size variable, we can hold 5 elements.

So, depending on the implementation, the queue's maximum capacity is either (array size -1) or equal to the array size. Using a size variable allows using the entire array.

But the user's question is about the logic for enqueue. So, in the case where the array is used with front and rear indices (without a size variable), the steps are as outlined earlier.

Another possible implementation is using a dynamic array that resizes when full, but the question doesn't mention dynamic arrays, so perhaps it's a fixed-size array.

In code, the enqueue function would look something like this (without size variable):

void enqueue(struct Queue* queue, int item) {

if (isFull(queue)) {

printf("Queue overflow\n");

return;

}

if (isEmpty(queue)) {

queue->front = queue->rear = 0;

} else {

queue->rear = (queue->rear + 1) % queue->capacity;

}

queue->array[queue->rear] = item;

}

Where isFull checks if (rear +1) % capacity == front.

isEmpty checks if front == -1.

But in this setup, the queue can hold capacity -1 elements.

Alternatively, with a size variable:

int isFull(struct Queue* queue) {

return (queue->size == queue->capacity);

}

void enqueue(struct Queue* queue, int item) {

if (isFull(queue)) {

printf("Queue overflow\n");

return;

}

int rear = (queue->front + queue->size) % queue->capacity;

queue->array[rear] = item;

queue->size++;

}

Here, front is the index of the first element, size is the current number. The rear is calculated as (front + size) % capacity. So, for each enqueue, the new element is placed at (front + size) mod capacity, then size increases by 1. This allows all capacity elements to be used.

This approach might be more efficient in terms of space usage.

But the user is asking how to think about the logic. So, the key points are:

1. Determine if the queue is full. If yes, handle overflow.

2. If the queue is empty, set front and rear appropriately (or just insert at the first position).

3. Otherwise, calculate the next rear position using modulo to wrap around.

4. Insert the element at the rear position.

The exact details depend on whether a size variable is used or not, and how the indices are managed.

Another thing to consider: when using a size variable, dequeuing is straightforward (increment front mod capacity and decrement size), but when not using a size variable, dequeuing requires updating front and checking if the queue becomes empty (front == rear after dequeue, set both to -1).

So, the logic for enqueue revolves around checking the full condition, handling the wrap-around, and updating the rear index or insertion position correctly.

Potential mistakes to avoid:

- Forgetting to use modulo operation when incrementing rear or calculating the insertion position, leading to array index out of bounds.

- Incorrectly checking the full condition (e.g., using rear == capacity -1 instead of modulo).

- Not handling the empty queue case properly, which could leave front and rear in an inconsistent state.

Testing edge cases:

- Enqueueing to a full queue.

- Enqueueing to an empty queue.

- Enqueueing when rear is at the end of the array (needs to wrap around to 0).

For example, if capacity is 5, and rear is 4, next enqueue should go to 0 if front is not 0.

But if front is 0 and rear is 4, then (4 +1) %5 =0 == front → queue is full.

So in that case, no more enqueues allowed.

But if the size approach is used, then when size is 5, queue is full. So with capacity 5, the queue can hold 5 elements.

So, the choice between the two approaches affects the maximum capacity.

In summary, the logic involves:

- Checking for full queue.

- Handling the wrap-around with modulo.

- Updating the rear/index correctly.

- Inserting the new element.

To implement the enqueue operation using an array in C, follow these steps, considering a circular queue approach to efficiently manage space:

Key Concepts:
Circular Array: Prevents wasted space by wrapping around indices using modulo operations.

Front and Rear Indices: Track the start and end of the queue.

Full and Empty Conditions:

Empty: front == -1

Full: (rear + 1) % capacity == front (when using front/rear without a size variable).


****************************************


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