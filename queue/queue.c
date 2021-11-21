// create a queue
#include<stdio.h>
#include<limits.h>

struct Queue
{
    /* data */
    int rear, front, size;
    unsigned capacity;
    int *arr;
};

struct Queue* createQueue(unsigned capacity)
{
    /* data */
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = queue->front = 0;
    queue->rear = capacity-1; //Imp
    queue->capacity = capacity;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
}

int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size+1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
    return INT_MIN;
    return queue->arr[queue->rear];
}

int main(){
    struct Queue* queue = createQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",
           dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}