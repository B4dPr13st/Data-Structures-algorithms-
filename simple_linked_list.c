#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*Struct that defines the list, remembering that 
the instruction: struct listCell *next
is a autoref struct, in that case is a struct that
points to the next struct*/

typedef struct listCell
{
	int item;
	struct listCell *next;
}cell;

//Function that removes head's elements
void delete(cell **pReceived)
{
	cell *current;
	if ((*pReceived)->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		current = (*pReceived)->next;
		(*pReceived)->next = current->next;
		free(current);
	}
}

//Function to search/go through the list elements
void search(cell **pReceived)
{
	cell *current;
	if ((*pReceived)->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		current = (cell *) malloc(sizeof(cell));
		current = (*pReceived)->next;
		while(current != NULL)
		{
			printf("\nValue: %d\n", current->item);
			current = current->next;
		}
	}
}

//function to insert in the start
void add(cell **pReceived)
{
	cell *current;
	int value;
	printf("\nPut the value to insert:\n");
	scanf("%d", &value);
	current = (cell *) malloc(sizeof(cell));
	current->item = value;
	current->next = (*pReceived)->next;
	(*pReceived)->next = current;
}

//Initialization of binded list
void initList(cell **pReceived)
{
	(*pReceived)->next = NULL;
}

int main()
{
	cell *pList;
	int option = 0;
	pList = (cell *) malloc(sizeof(struct listCell));
	initList(&pList);
	for (;;)
	{
		printf("\n1 - Insert");
		printf("\n2 - Search");
		printf("\n3 - Remove");
		printf("\n4 - Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				add(&pList);
				break;
			case 2:
				search(&pList);
				break;
			case 3:
				delete(&pList);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}