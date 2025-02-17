struct Stack{
    int top;
    int arr[5];
};
struct queue
{
    int top;
    int arr[5];
};


//Stack Operation
void push(struct Stack *stack, int daya);
int pop(struct Stack *stack);
void display(struct Stack *stack);
//queue operation
void push(struct queue *queue,int data);
int pop(struct queue *queue);
void display(struct queue *queue);
