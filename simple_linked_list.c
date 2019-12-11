#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Struct that defines the list, remembering that 
the instruction: struct bindList *next
is a autoref struct, in that case is a struct that
points to the next struct*/

typedef struct bindList
{
	int item;
	struct bindList *next;
}NODE;

//Function that removes head's elements
void rem(NODE *head)
{
	NODE *current = head;
	if (head->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		//Catching the pointer to the next NODE
		current = head->next;
		//Catching the pointer next of the current NODE and atributing to the previous NODE
		head->next = current->next;
		//Deallocating the memory of the NODE
		free(current);
	}
}

//Function to search/go through the list elements
void list_show(NODE *head)
{
	NODE *current = head;
	if (head->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		while(current != NULL)
		{
			if (current->next != NULL)
			{
				printf("\nList item: %d\n", current->item);
			}
			//The actual NODE receives the next NODE pointer
			current = current->next;
		}
	}
}

//Function to search/go through the list elements
void search(NODE *head, int wanted)
{
	NODE *current = head;
	if (head->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		while(current != NULL)
		{
			if (current->item == wanted)
			{
				printf("\nThe value was found!\nValue: %d\n", current->item);
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

//function to insert in the start
NODE* add(NODE *head)
{
	NODE *current;
	int value;
	printf("\nPut the value to insert:\n");
	scanf("%d", &value);
	current = (NODE*) malloc(sizeof(NODE));
	current->item = value;
	//The new NODE turns into the list head
	current->next = head;
	return head;
}

//Initialization of binded list
NODE* initList(NODE *head)
{
	return NULL;
}

int main()
{
	NODE *head;
	int option = 0;
	int wanted;
	head = initList(head);
	for (;;)
	{
		printf("\n------------\n");
		printf("\n1 - Insert");
		printf("\n2 - Search");
		printf("\n3 - Show list items");
		printf("\n4 - Remove");
		printf("\n5 - Exit\n");
		printf("--------------\n");
		printf("Select an option:\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				add(&head);
				break;
			case 2:
				printf("\nEnter the value that you want to find:\n");
				scanf("%d", &wanted);
				search(head, wanted);
				break;
			case 3:
				list_show(head);
				break;
			case 4:
				rem(head);
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
