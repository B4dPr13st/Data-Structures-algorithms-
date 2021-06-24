# Stacks

![](https://dkrn4sk0rn31v.cloudfront.net/uploads/2020/11/o_que_e_e_como_funciona_a_estrutura_de_dados_pilha.png)

<br>A stack is a very common data structure in operating systems.
Stacks can be used to implement:
- Inversion of lists
- Store data
- Implement LIFOs

Current practical uses of batteries are:

- Processing languages, such as compilers
- Forward and back buttons on music players and web browsers

## LIFOs

A **LIFO** is a concept that describes how some data structures work. This concept 
consists of the idea that **Last In is Last Out**.

In a stack, elements are always added to the top and only the top 
element of the list can be removed, navigating a list is not possible.

## Abstract Data Type 

As explained earlier with linked lists, each language has its 
own abstraction  **ADT** of data structures. 
As we are using **C** and **Python**, both representations will be presented here.

**C ADT** Example:

```C
#define MAX_STACK_SIZE 10

struct Stack
{
    int current_size;
    int items[MAX_STACK_SIZE];//We store the items in the stack using an array, but we can also create stacks with lists
};
```

**Python ADT** Example:

```Python
#stack implementation using a singly linked list
#Node of list
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    def __init__(self):
        self.head = Node("head")
        self.size = 0
```

## Implementation of Stacks

Because a stack is a more restrictive data structure, we can't 
perform the same operations on it that we use on lists.

The main operations of a stack are **Push**, **Pop** and **Peek**.

#### Push

As stated earlier, we can only add elements to the top of our stack
, so elements below the top are not accessible.

Below are the interpretations of **Push**:

**C** Examples: 
```C
void push(STACK *Stack, int item){
    if (Stack->current_size == MAX_STACK_SIZE)//First we must check before add items on stack to see if it isn't full
    {
        printf("Stack overflow\n");
    }
    else
    {
        Stack->items[Stack->current_size++] = item;//The first item of stack is stored in array
    }
}
```

**Python** Examples:
```Python
#Insert a value into the stack
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head.next
        self.head.next = new_node
        self.size += 1

#string representation of stack
    def __str__(self):
        current = self.head.next
        out = ""
        while current:
           out += str(current.value) + "->"
           current = current.next
        return out[:-3]
```

Along with the **Push** implementation in **Python** we have 
the string format method, so we can know what's on the 
**Stack** without needing to unstack as we can't navigate the **Stack**.

#### Pop

The operation of removing **Stacks**, like 
that of other structures, is called **Pop**.

**C** Example:
```C
int pop(STACK *Stack){
    if (is_empty(Stack))//We can't pop from an empty stack
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return Stack->items[--Stack->current_size];
    }
}
```

**Python** Example:
```Python
#Remove from stack and return
    def pop(self):
        if self.isEmpty():
            raise Exception("Stack is empty!")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return remove.value
```

#### Peek

To find the top element of a **Stack**
, we use a method called **Peek**.

**C** Example:
```C
int peek(STACK *Stack){
    if (is_empty(Stack))//We can't peek from an empty stack
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return Stack->items[Stack->current_size - 1];
    }   
}
```

**Python** Example:
```Python
#Get the item on top of stack
    def peek(self):
        # Checking if stack is empty before getting the top item
        if self.isEmpty():
            raise Exception("Stack is empty!")
        return self.head.next.value
```

## Complexity analysis and comparisons

Time to make comparisons and final considerations.

The complexity analysis is given in big O notation.

**Peek**, **Push**, **Pop** have a complexity of O(1)
, as they don't need to browse the list and interact 
with a specific position.

However, if we need to unstack to search for some element, the 
complexity becomes O(n), since we will have to remove element 
by element from the stack.

## Finishing

This was a short summary and demonstration 
of implementing **Stacks**, I hope you enjoyed it! :D

Good luck with your studies!

![](https://media.giphy.com/media/ZBVhKIDgts1eHYdT7u/giphy.gif)