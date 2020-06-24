
# Linked Lists
![Simple linked list example](https://pt-static.z-dn.net/files/d99/fe8947a2971899cd1702a4e9e57248be.png)

<br>    Suppose you are implementing a customer registration system, you have no way of knowing the number of customers who will register through your system.

Assuming you used an **Array** to store the registered data, we would have 2 problems, namely:<br><br>
1. **Array** is a static data structure, so once declared it will always have the same number of indexes.<br><br>
2. Since you don't know the number of customers you could think about declaring an **Array** with thousands of indexes, but that would bring you a huge memory expense.<br><br>

But what if instead of using **Arrays** you used a **dynamic data structure** that added or removed indexes as needed?

That's where **Linked Lists** come in!

**Linked Lists** are **dynamic structures** that can store multiple data at the same time, in addition to being **dynamic**, that is, it is possible to add or remove **nodes**, as the **indexes** of a **List** are called, unlike a **Array** that, once declared, it is not possible to add or remove new indexes.

There are several types of implementations and **Lists**, but here only the **Simple Linked Lists (SLL)** and **Double Linked Lists (DLL)** will be shown here.

## Abstract Data Types

Each language has its own way of representing the **ADT** of a given structure, here the languages ​​**C** and **Python** will be used.<br><br>

First the single linked list will be shown and then the double linked list.

Before proceeding it is important to know that the first node in the list is called **head node**, the others are known as **tail nodes.**

### Simple Linked List (SLL)

**C** example:
```c
struct SLList
{
    int Data; #Stored data can be of any type
    struct SLList *next; #Pointer to the next node
};
```
<br>

**Python** example:

```python
#Node class
class Node:
    #Method to initialize the node OBJ
    def __init__(self, data):
        self.data = data #Assign data
        self.next = None #Initialize next as NULL

#Linked List class
class LinkedList:
    #Method to initialize the SLL(Simply Linked List) OBJ(Object)
    def __init__(self):
        self.head = None
```

In **C**, as we can use **Pointers** the **struct** is used to define the structure of a **Node** and **pointers** are used to link the elements (**Nodes**) from the list, but as in Python we cannot use **pointers** we create two classes, one of them will be used to serve as a template for the creation of the **object** **Node** and the other will be used to create the **object** **List.**

### Double Linked List (DLL)

**C** example:
```c
struct DLList
{
    int data;
    struct DLList *next;
    struct DLList *next;
}
```
<br>

**Python** example:
```python
#Node of a DLL(Doubly Linked List)
class Node:
    def __init__(self, next=None, prev=None, data=None):
        self.next = next
        self.prev = prev
        self.data = data
```
<br>

The difference between **Simple Linked Lists** and **Double Linked Lists** is the presence of a **pointer** to the previous **node**, which allows us to go through the **list** in two directions.

## Implementation of Simple Linked Lists

Various operations can be done with **Lists**, here basic operations such as **insertion**, **removal**, **search** and **sorting** will be shown.

#### Insertion

Here, two types of insertion were implemented, namely:<br>

- Head insertion.
- Insertion at the tail end.

Both implemented in **C** and **Python**.

**C** examples:
```c
//function to insert in List's head
NODE* add(NODE *head)
{
	NODE *current;//Declaration of a new node
	int value//Value to be stored in node data
	scanf("%d", &value);
	current = (NODE*) malloc(sizeof(NODE));//Allocation of node
	current->item = value;//Assigning the value to the node element
	//The new NODE turns into the list head
        /*
            Turning the new node at the head of the list 
            and making the next element's 
            pointer point to the old head node
        */
	current->next = head;
	return current;
}
```
<br>

```c
//Function to insert an item on the List's tail
NODE* add_in_end(NODE *head) 
{ 
	int value;
	NODE *current = head;//Making a node store head's pointer/reference
	scanf("%d", &value);
    //Allocate a new node
    NODE *new_node = (NODE*) malloc(sizeof(NODE)); 
    new_node->item = value;
    /*
        Making the pointer next to the node point to NULL, 
        since it will be the last node in the list.
    */
    new_node->next = NULL;
	if (head == NULL)//Always check if head is NULL(Empty list)
	{
		head = new_node;
		return head;
	}
        //To add the node at the end of the list we have to know the end of it, so we go through it
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;//Here the reference is changed again
    return head;//And the head ref is returned by function     
}
```
<br>

**Python** examples:
```python
#This method inserts a node at SLL's head
    def push(self, new_item):
        #Allocate the node
        new_node = Node(new_item)
        new_node.next = self.head
        self.head = new_node
```
<br>

```python
#This method inserts a node on SLL's tail
    def pushOnTail(self, new_item):
        new_node = Node(new_item)
        #If SLL is empty the new node turns into SLL's head
        if self.head is None:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
```

Note: Note that these functions in **Python** are **methods** of the **class** **List.**

#### Removing

As with insertion, removal of the **head** and **tail** ends was implemented here.

**C** examples:
```c
//Function that removes head's elements
NODE* rem(NODE *head)
{
	NODE *current = head;
	if (head == NULL)
	{
		printf("\nEmpty list!\n");
	}
	//Catching the pointer to the next NODE
	head = current->next;
	//Deallocating the memory of the NODE
	free(current);
	return head;
}
```
<br>

```c
//Function to remove the last node of list
NODE* rem_from_tail(NODE* head)
{
	NODE* current = head;
	if (head == NULL)
	{
		printf("\nEmpty list!\n");
		return NULL;
	}
	if (head->next == NULL)
	{
		head = NULL;
		return head;
	}
	
	//Find the node that is before the last node
	NODE* penultimate_node = head;
        /*
            As we need to know which last node to remove it 
            we go through the list again
        */
	while (penultimate_node->next->next != NULL)
	{
		penultimate_node = penultimate_node->next;
	}
	free(penultimate_node->next);
	penultimate_node->next = NULL;
	return head;
}
```
<br>

**Python** examples:
```python
#This isn't a class method
def remFromHead(head):
    if not head:
        return None
    aux = head
    head = head.next
    aux = None
    print("Head removed!")
    return head
```
<br>

```python
#This isn't a class method
#Function to delete SLL's node for tail
def remFromTail(head):
    if head == None:
        return None
    if head.next == None:
        head = None
        return None
    penultimate = head
    while penultimate.next.next:
        penultimate = penultimate.next
    penultimate.next = None
    print("Tail removed!")
    return head
```

#### Search

The **search** operation on a linked list is quite simple, and can be implemented using just a **while.**

**C** example:
```c
//Function to search/go through the list elements
void search(NODE *head, int wanted)
{
	NODE *current = head;
	if (head == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		while(current != NULL)
		{
			if (current->item == wanted)
			{
				printf("The value was found!\n");
				return;
			}
			current = current->next;
		}
		if (current == NULL)
		{
			printf("The value wasn't found!\n");
		}
	}
}
```
<br>

**Python** example:
```python
#List's class method
#This method search an item in list
    def search(self, x):
        current = self.head

        while current != None:
            if current.data == x:
                return True
            current = current.next
        return False
```

#### Sorting

Last but not least, we have the **sorting** operation, which is a little more complex since we are dealing with many **pointers**. There are several **sorting algorithms**, but what was implemented here was the **Selection Sort**.

**C** example:
```c
//Function to order using selectionsort algorithm
NODE* sorting_list(NODE *head) 
{ 
    NODE *aux, *aux2, *aux3, *aux4, *r; 
    aux = head;
    aux2 = head; 
    // While aux2 is not the last node 
    while (aux2->next != NULL) { 
        aux3 = aux2->next;
        aux4 = aux2->next; 
        // While aux4 is pointing to a valid node 
        while (aux4 != NULL) { 
            if (aux2->item > aux4->item) { 
                // If aux4 appears immediately after aux2 
                if (aux2->next == aux4) { 
                    //Case 1: aux2 is the head of the linked list 
                    if (aux2 == head) { 
                        //Move aux4 before aux2 
                        aux2->next = aux4->next; 
                        aux4->next = aux2; 
                        //Swap aux2 and aux4 pointers 
                        r = aux2; 
                        aux2 = aux4; 
                        aux4 = r; 
                        aux3 = aux4; 
                        //Update the head 
                        head = aux2; 
                        //Skip to the next element as it is already in order 
                        aux4 = aux4->next; 
                    } 
                    //Case 2: aux2 is not the head of the linked list 
                    else { 
                        // Move aux4 before aux2 
                        aux2->next = aux4->next; 
                        aux4->next = aux2; 
                        aux->next = aux4; 
                        // Swap aux2 and aux4 pointers 
                        r = aux2; 
                        aux2 = aux4; 
                        aux4 = r; 
                        aux3 = aux4; 
                        // Skip to the next element as it is already in oraux4er 
                        aux4 = aux4->next; 
                    } 
                } 
                //If aux2 and aux4 have some non-zero number of nodes in between them 
                else { 
                    //Case 3: aux2 is the head of the linked list 
                    if (aux2 == head) { 
                        //Swap aux2->next and aux4->next 
                        r = aux2->next; 
                        aux2->next = aux4->next; 
                        aux4->next = r; 
                        aux3->next = aux2; 
                        //Swap aux2 and aux4 pointers 
                        r = aux2; 
                        aux2 = aux4; 
                        aux4 = r; 
                        aux3 = aux4; 
                        //Skip to the next element as it is already in oraux4er 
                        aux4 = aux4->next; 
                        //Update the head 
                        head = aux2; 
                    } 
                    //Case 4: aux2 is not the head of the linked list 
                    else { 
                        //Swap aux2->next and aux4->next 
                        r = aux2->next; 
                        aux2->next = aux4->next; 
                        aux4->next = r; 
                        aux3->next = aux2; 
                        aux->next = aux4; 
                        //Swap aux2 and aux4 pointers 
                        r = aux2; 
                        aux2 = aux4; 
                        aux4 = r; 
                        aux3 = aux4; 
                        //Skip to the next element as it is already in oraux4er 
                        aux4 = aux4->next; 
                    } 
                } 
            } 
            else { 
                //Update aux3 and skip to the next element as it is already in order 
                aux3 = aux4; 
                aux4 = aux4->next; 
            } 
        } 
        aux = aux2; 
        aux2 = aux2->next; 
    } 
    return head; 
}
```
<br>

**Python** example:
```python
#This isn't a class method
#Function to sort SLL using selectionsort
def selectionSort(head):
    a = b = head

    while b.next:
        c = d = b.next

        while d:
            if b.data > d.data:
                if b.next == d:
                    if b == head:
                        b.next = d.next
                        d.next = b

                        b,d = d,b
                        c = d

                        head = b

                        d = d.next
                    else:
                        b.next = d.next
                        d.next = b
                        a.next = d

                        b, d = d, b
                        c = d

                        d = d.next
                else:
                    if b == head:
                        r = b.next
                        b.next = d.next
                        d.next = r
                        c.next = b

                        b, d = d, b
                        c = d

                        d = d.next

                        head = b
                    else:
                        r = b.next
                        b.next = d.next
                        d.next = r
                        c.next = b
                        a.next = d

                        b, d = d, b
                        c = d

                        d = d.next
            else:
                c = d
                d = d.next

        a = b
        b = b.next
    return head
```

## Implementation of Double Linked Lists

Just as we have implemented basic operations with simple lists, we will also do with double **linked lists**.

**C** implementation:
```c
struct DLList
{
    int data;
    struct DLList *next;//Pointer to next Node
    struct DLList *prev;//Pointer to previous Node
};
```
<br>

**Python** implementation:
```python
#Node of a DLL(Doubly Linked List)
class Node:
    def __init__(self, next=None, prev=None, data=None):
        self.next = next
        self.prev = prev
        self.data = data

class DoublyLinkedList:
    def __init__(self):
        self.head = None
```

The operations with double linked lists are a little more complex, since we now have 2 **pointers** to deal with.

#### Insertion

Here, again, two types of insertion were implemented, namely:<br>

- Head insertion.
- Insertion at the tail end.

**C** examples:
```c
//Function to add a node at the DLL's head
NODE* push(NODE* head, int new_item)
{
    //Node allocation
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = new_item;
    new_node->next = head;
    new_node->prev = NULL;

    //Change the head previous to new node
    if (head != NULL)
    {
        head->prev = new_node;
    }

    head = new_node;
    return head;   
}
```
<br>

```c
//Function to insert a node in DLL's tail
NODE* pushToTail(NODE* head, int new_item)
{
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    NODE* last = head;
    new_node->data = new_item;
    new_node->next = NULL;

    //Check if the DLL is empty
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }
    
    //We need to get the last node of DLL
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return head;
}
```
<br>

**Python** examples:
```python
#this is a list class method
#This method inserts an item on DLL's head
def push(self, new_key):
    new_node = Node(data=new_key)
    new_node.next = self.head
    new_node.prev = None

    if self.head is not None:
        self.head.prev = new_node

    self.head = new_node
```
<br>

```python
#This is a list class method
#This method inserts a node at DLL's tail
def pushOnTail(self, new_key):
    new_node = Node(data=new_key)
    last = self.head
    new_node.next = None

    if self.head is None:
        new_node.prev = None
        self.head = new_node
        return

    while last.next is not None:
        last = last.next

    last.next = new_node
    new_node.prev = last
```

As seen now, we have to take the previous node into account when inserting a new node.

#### Removing

Unlike the simple list, here only the generic removal of nodes from the list has been implemented.

**C** example:
```c
//Function to remove a specific node in DLL 
void remv(NODE* *head, NODE* to_rem)
{
    //If one of them is NULL, just return
    if (*head == NULL || to_rem == NULL)
    {
        return;
    }

    //The node to delete is DLL's head
    if (*head == to_rem)
    {
        *head = to_rem->next;
    }

    //Next is changed only if node to be deleted isn't the last node
    if (to_rem->next != NULL)
    {
        to_rem->next->prev = to_rem->prev;
    }
    
    //Next is changed only if node to be deleted isn't the first node
    if (to_rem->prev != NULL)
    {
        to_rem->prev->next = to_rem->next;
    }
    free(to_rem);
    return;
}
```
<br>

**Python** example:
```python
import gc

#This is a list class method
#This method removes a node from DLL
    def rem(self, toBeDeleted):
        if self.head is None or toBeDeleted is None:
            return

        if self.head == toBeDeleted:
            self.head = toBeDeleted.next

        if toBeDeleted.next is not None:
            toBeDeleted.next.prev = toBeDeleted.prev

        if toBeDeleted.prev is not None:
            toBeDeleted.prev.next = toBeDeleted.next

        gc.collect()
```

#### Search

**C** example:
```c
//Function to search/go through the list elements
void search(NODE *head, int wanted)
{
	NODE *current = head;
	if (head == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		while(current != NULL)
		{
			if (current->data == wanted)
			{
				printf("\nThe value was found!\n");
				return;
			}
			current = current->next;
		}
		if (current == NULL)
		{
			printf("\nThe value wasn't found!\n");
		}
	}
}
```
<br>

**Python** example:
```python
#This is a list class method
# This method search an item in list
    def search(self, x):
        current = self.head

        while current != None:
            if current.data == x:
                return True
            current = current.next
        return False
```

#### Sorting

The sorting algorithm implemented with double linked lists was the **merge sort**.

**C** example:
```
//Function to split a DLL into two DLLs with half size
NODE* split(NODE* head)
{
    NODE *first = head, *second = head;
    while (first->next && first->next->next)
    {
        first = first->next->next;
        second = second->next;
    }
    NODE *aux = second->next;
    second->next = NULL;
    return aux;
}

//Function that realizes merge sort
NODE* mergeSort(NODE* head)
{
    if (!head || !head->next)
    {
        return head;
    }
    NODE *second = split(head);
    
    //Recursion for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);

    //Merge the two sorted halves
    return merge(head, second);
}

//Function to merge two DLL
NODE* merge(NODE* first, NODE* second)
{
    //First DLL is empty
    if (!first)
    {
        return second;
    }
    
    //Second DLL is empty
    if (!second)
    {
        return first;
    }
    
    //Pick the smaller value
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
    
}
```
<br>

**Python** example:
```python
#Here we have methods of the list class
#This method merge two LLs
    def merge(self, first, second):
        if first is None:
            return second

        if second is None:
            return first

        if first.data < second.data:
            first.next = self.merge(first.next, second)
            first.next.prev = first
            first.prev = None
            return first
        else:
            second.next = self.merge(first, second.next)
            second.next.prev = second
            second.prev = None
            return second

    #This method do the merge sort
    def mergeSort(self, aux):
        if aux is None:
            return aux
        if aux.next is None:
            return aux

        second = self.split(aux)

        #Recrusion for left and right halves
        aux = self.mergeSort(aux)
        second = self.mergeSort(second)

        #Merge the sorted halves
        return self.merge(aux, second)

    #This method splits DLL into two DLLs
    def split(self, aux):
        fast = slow = aux
        while True:
            if fast.next is None:
                break
            if fast.next.next is None:
                break
            fast = fast.next.next
            slow = slow.next

        aux = slow.next
        slow.next = None
        return aux
```

## Complexity analysis and comparisons

Time to make comparisons and final considerations.

The complexity analysis is given in big O notation.

### Difference between single and double linked lists

Both work with data independent nodes. These nodes have the value of the element and a **pointer** to the next element in the list. As they are **not in continuous sequence in memory** (or other means), it is possible to easily insert and remove an element simply by changing the element's pointer immediately before the position where the element in question is being manipulated.

The linked lists, in general, have the ability to insert and remove the tip (one or both, in the case of a pair) very quickly **(O (1))**. They are usually bad for insertion and removal in the middle or when it is necessary to do a search in it, since it is necessary to go through it until it is complete until you find the element **(O(N))**. The insertion or removal itself is also quick, the problem is that to get to the position where the operation will be performed it has **linear complexity**. And it is almost always necessary to browse through the list.

Today linked lists are rarely used. There are usually more efficient structures for most cases (stacks, trees, hashes, even simple vectors, although eventually some of these structures may use the linked list in a complementary way). It is rare to have a requirement that the list meets well.

## Finishing

This was a short summary and demonstration of implementing linked lists in a simple or doubly linked way, I hope you enjoyed it! : D

Good luck with your studies!

![](https://media.giphy.com/media/79ZFYdMsStRYI/giphy.gif)  