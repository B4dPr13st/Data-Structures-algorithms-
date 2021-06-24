# Queues

![](https://www.mundojs.com.br/wp-content/uploads/2020/06/queue-basic.png)

**Queues** data structures work just like a bank queue or a movie queue, for example,
where the first individual to arrive will be served first.

Among the examples of computational applications of a **Queue** we can mention:

- Packet exchange within a network, where routers and switches use queues to organize incoming and outgoing packets
- Print control, where pages and documents to be printed are also organized in a **Queue**

## FIFOs

**Queues** are data structures of type **FIFO(First In First Out)**.

As mentioned earlier, this is exactly how **queues** work, both computationally and in real life

## Abstract Data Type

As explained earlier with **Linked Lists** and **Stacks**, each language has its own abstraction ADT of data structures. 
As we are using **C** and **Python**, both representations will be presented here.

**C ADT** Example:
```C
#define MAX_SIZE 10

struct Queue
{
	int current_size;
	int head;
	int tail;
	int items[MAX_SIZE];
};
```

**Python ADT** Example:
```Python
MAX_Q_SIZE = 100

#Class used for queue implementation
class MyQueue():
    def __init__(self, capacity=MAX_Q_SIZE):
        self.front = self.size = 0
        self.rear = capacity - 1
        self.Q = [None] * capacity
        self.capacity = capacity
```

## Implementation of Stacks

**Queues** are not as restrictive as **Stacks**, so we can navigate through them. 
In addition, **Queues** 
have two main insertion and removal operations, called **Enqueue** and **Dequeue**.

#### Enqueue

Below are the implementations of the **Enqueue** operation.

**C** Example:
```C
//Function to add to queue
void enqueue(myQueue *queue, int item)
{
	if (queue->current_size >= MAX_SIZE)
	{
		printf("QUEUE OVERFLOW!\n");
	}
	else
	{
		queue->tail = (queue->tail + 1) % MAX_SIZE;
		queue->items[queue->tail] = item;
		queue->current_size++;
	}
}
```

**Python** Example:
```Python
    def EnQueue(self, item):
        if self.IsFull():
            print("Full")
            return
        self.rear = (self.rear + 1) % (self.capacity)
        self.Q[self.rear] = item
        self.size += 1
        print("Enqueued", str(item))
```

#### Dequeue

Below are the implementations of the **Dequeue** operation.

**C** Example:
```C
//Function to remove of queue
int dequeue(myQueue *queue)
{
	if (is_empty(queue))
	{
		printf("QUEUE UNDERFLOW!\n");
		return -1;
	}
	else
	{
		int dequeued = queue->items[queue->head];
		queue->head = (queue->head + 1) % MAX_SIZE;
		queue->current_size--;
		return dequeued;
	}
}
```

**Python** Example:
```Python
    def DeQueue(self):
        if self.IsEmpty():
            print("Empty")
            return

        print("Dequeued", str(self.Q[self.front]))
        self.front = (self.front + 1) % (self.capacity)
        self.size -= 1
```

## Complexity analysis and comparisons

In **Queues** both **Enqueue** and **Dequeue** have O(1), 
since they will always interact with specific positions in the structure.

**Search operations** within a **Queue** have O(n) complexity, since we will have to go through the list to find 
the element with the possibility of it being at the end of the queue, requiring a long search time .

## Finishing

This was a short summary and demonstration of implementing **Queues**, I hope you enjoyed it! :D

Good luck with your studies!

![](https://media.giphy.com/media/LFEjnqmVmbKk8/giphy.gif)