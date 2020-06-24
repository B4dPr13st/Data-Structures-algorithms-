#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Abstract Data Type of Doubly Linked List
typedef struct DLL
{
    int data;
    struct DLL* next;
    struct DLL* prev;
}NODE;

//Function to reverse a DLL
NODE* reverse(NODE* head);

//Function to merge two DLL
NODE* merge(NODE* first, NODE* second);

//Function that realizes merge sort
NODE* mergeSort(NODE* head);

//Function to split a DLL into two DLLs with half size
NODE* split(NODE* head);

//Swap function
void swap(int *a, int *b);

//Function to remove a specific node in DLL 
void remv(NODE* *head, NODE* to_rem);

//Function to search/go through the list elements
void search(NODE *head, int wanted);

//Function to show the DLL items
void showList(NODE* head, int opt);

//Function to insert a node in DLL before a given node
NODE* pushBfr(NODE* head, NODE* next_n, int new_item);

//Function to insert a node in DLL's tail
NODE* pushToTail(NODE* head, int new_item);

//Function to insert node after a given node
NODE* pushAftr(NODE* previous, int new_item);

//Function to add a node at the DLL's head
NODE* push(NODE* head, int new_item);

//Function to initialize the DLL
NODE* initDLL(NODE* head);

int main()
{
    NODE *head;
	int option = 0;
    int optt = 0;
	int wanted;
	head = initDLL(head);
	for (;;)
	{
		printf("--------------");
		printf("\n1 - Insert");
		printf("\n2 - Search");
		printf("\n3 - Show list items");
		printf("\n4 - Sort list items");
		printf("\n5 - Reverse the list items");
		printf("\n6 - Remove");
		printf("\n7 - Exit\n");
		printf("--------------\n");
		printf("Select an option:\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\nYou want to insert an item on head or tail?\n");
				printf("1 - Head\n");
				printf("2 - Tail\n");
				int selected;
				scanf("%d", &selected);
				if (selected == 1)
				{
                    printf("Enter the key to insert: ");
                    int key;
                    scanf("%d", &key);
					head = push(head, key);
					break;
				}
				else if(selected == 2)
				{
                    printf("Enter the key to insert: ");
                    int keyy;
                    scanf("%d", &keyy);
					head = pushToTail(head, keyy);
					break;
				}
				else
				{
					printf("Enter a valid value!\n");
					break;
				}
			case 2:
				printf("\nEnter the value that you want to find:\n");
				scanf("%d", &wanted);
				search(head, wanted);
				break;
			case 3:
				showList(head, optt);
				break;
			case 4:
				head = mergeSort(head);
				break;
			case 5:
				head = reverse(head);
				break;
			case 6:
				if (head->next == NULL)
                {
                    remv(&head, head);
				    break;
                }
                else
                {
                    remv(&head, head->next);
				    break;
                }
			case 7:
				exit(0);
		}
	}
    return 0;
}

//Function to initialize the DLL
NODE* initDLL(NODE* head)
{
    head = NULL;
    return head;
}

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

//Function to insert node after a given node
NODE* pushAftr(NODE* previous, int new_item)
{
    if (previous == NULL)
    {
        printf("A non NULL node is necessary!");
        return NULL;
    }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = new_item;
    new_node->next = previous->next;//New node receives the previous next pointer
    previous->next = new_node;//Previous next receives the new node poiter
    new_node->prev = previous;//New node previous receives the previous node pointer

    //Update the next node previous as new node
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    return new_node;
}

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

//Function to insert a node in DLL before a given node
NODE* pushBfr(NODE* head, NODE* next_n, int new_item)
{
    if (next_n == NULL)
    {
        printf("A non NULL node is necessary");
        return head;
    }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = new_item;
    //Here we made the inverse steps of pushAftr
    new_node->prev = next_n->prev;
    next_n->prev = new_node;
    new_node->next = next_n;

    //Update the next pointer of the new node previous node
    if (new_node->prev != NULL)
    {
        new_node->prev->next = new_node;
        return head;
    }
    else
    {
        head = new_node;
        return head;
    }
}

//Function to show the DLL items
void showList(NODE* head, int opt)
{
    NODE* current = head;
    int loop = 0;
    printf("Showing list\n");
    while (current != NULL)
    {
        printf("DLL item #%d: %d\n", loop, current->data);
        loop += 1;
        current = current->next;
    }
    printf("Empty list!");
}

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

//Swap function
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

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

//Function to reverse a DLL
NODE* reverse(NODE* head)
{
    NODE* aux = NULL;
    NODE* current = head;

    //Swap the next and prev pointers for all DLL's nodes
    while (current != NULL)
    {
        aux = current->prev;
        current->prev = current->next;
        current->next = aux;
        current = current->prev;
    }
    
    if (aux != NULL)
    {
        head = aux->prev;
    }
    return head;
}