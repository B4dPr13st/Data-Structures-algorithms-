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
void delete(cell **head)
{
	cell *current;
	if ((*head)->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		//Catching the pointer to the next node
		current = (*head)->next;
		//Catching the pointer next of the current node and atributing to the previous next node
		(*head)->next = current->next;
		free(current);
	}
}

//Function to search/go through the list elements
void search(cell **head, int wanted)
{
	cell *current;
	if ((*head)->next == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		current = (cell *) malloc(sizeof(cell));
		current = (*head)->next;
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
void add(cell **head)
{
	cell *current;
	int value;
	printf("\nPut the value to insert:\n");
	scanf("%d", &value);
	current = (cell *) malloc(sizeof(cell));
	current->item = value;
	//The new node turns into the list head
	current->next = (*head)->next;
	(*head)->next = current;
}

//Initialization of binded list
void initList(cell **head)
{
	(*head)->next = NULL;
	(*head)->previous = NULL;
}

int main()
{
	cell *head;
	int option = 0;
	int wanted;
	head = (cell *) malloc(sizeof(struct listCell));
	initList(&head);
	for (;;)
	{
		printf("\n------------\n");
		printf("\n1 - Insert");
		printf("\n2 - Search");
		printf("\n3 - Remove");
		printf("\n4 - Exit\n");
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
				search(&head, wanted);
				break;
			case 3:
				delete(&head);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
