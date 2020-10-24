#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

typedef struct stack
{
    int current_size;
    int items[MAX_STACK_SIZE];//We store the items in the stack using an array, but we can also create stacks with lists
}STACK;

//This function initializes our stack
STACK* create_stack();

//This function inserts a new item on stack
void push(STACK *Stack, int item);

//This function removes an item from stack
int pop(STACK *Stack);

//This function shows the item on top of stack
int peek(STACK *Stack);

//Check if stack is empty
int is_empty(STACK *Stack);

int main()
{
    STACK *Stack = create_stack();//We must create an pointer to storage the address of stack
    push(Stack, 10);
    push(Stack, 20);
    push(Stack, 15);
    push(Stack, 40);
    int x, y;
    x = pop(Stack);
    printf("pop: %d\n", x);
    y = peek(Stack);
    printf("peek: %d\n", y);
    x = pop(Stack);
    printf("pop: %d\n", x);
    y = peek(Stack);
    printf("peek: %d\n", y);
    x = pop(Stack);
    printf("pop: %d\n", x);
    y = peek(Stack);
    printf("peek: %d\n", y);
    x = pop(Stack);
    printf("pop: %d\n", x);
    return 0;
}

STACK* create_stack(){
    STACK *new_stack = (STACK*)malloc(sizeof(STACK));//Dynamic allocation
    new_stack->current_size = 0;//Initializing stack size with 0
    return new_stack;//Return the stack pointer
}

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

int is_empty(STACK *Stack){
    if (Stack->current_size == 0)
    {
        return 1;
    }
    return 0;
}