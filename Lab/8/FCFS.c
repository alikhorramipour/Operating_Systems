#include <stdio.h>
//#include <queue.h>
#include <stdlib.h> 
#include <limits.h> 

#define MAX_PRCS 1000

struct process {
	int pid;
	int bt;
	int wt,tt;
}p[10];

struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 
  
// Driver program to test above functions./ 
int main() 
{ 
	int n;							// number of processes
	int burst[MAX_PRCS];			// burst time of each process
	int wait[MAX_PRCS] = {0};		// waiting time of each process
	int finish[MAX_PRCS] = {0};		// finishing time of each process

	int wait_sum = 0;
	int finish_sum = 0;

	scanf("%d\n", &n);				// receive n from user

    struct Queue* queue = createQueue(n);
    
    int tmp; 						// temporary int for storing time for each process
    burst[0] = 0;
    for(int i = 1; i < n; i++){ 	// receive burst time of each process
    	scanf("%d\n", &tmp);
    	burst[i] = tmp;
    }

    for(int i = 1; i < n; i++){ 	// calculate waiting time of each process
    	for(int j = i; j < n; j++){
    		wait[i] += burst[j];
    	}
    	wait_sum += wait[i];
		printf("wait[i] = %d\n", wait[i]);
    }

    for(int i = 0; i < n; i++){		// calculate finishing time of each process
    	finish[i] = wait[i] + burst[i];	
		printf("finish[i] = %d\n", finish[i]);
    	finish_sum += finish[i];
    }
	
	printf("sum waiting time: %d\n", wait_sum);
	printf("sum finishing time: %d\n", finish_sum);
	
    printf("Average waiting time: %f\n", (double)wait_sum / n);
    printf("Average finishing time: %f\n", (double)finish_sum / n);

    /*enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    printf("%d dequeued from queue\n\n", dequeue(queue)); 
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); */
  
    return 0; 
} 