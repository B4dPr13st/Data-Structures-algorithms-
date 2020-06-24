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

//Function to remove the first occurrence of a specified node
void rem_selected_node(NODE* head, int item);

//Function to remove the last node of list
NODE* rem_from_tail(NODE* head);

//Function that removes head's elements
NODE* rem(NODE *head);

//Function to reverse the linked list
NODE* reverse_list(NODE *head);

//Function to order using selectionsort algorithm
NODE* sorting_list(NODE *head);

//Function to search/go through the list elements
void list_show(NODE *head);

//Function to search/go through the list elements
void search(NODE *head, int wanted);

//Function to insert an item on the list's tail
NODE* add_in_end(NODE *head); 

//function to insert in list's head
NODE* add(NODE *head);

//Initialization of linked list
NODE* initList(NODE* head);

int main()
{
	NODE *head;
	int option = 0;
	int wanted;
	head = initList(head);
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
					head = add(head);
					break;
				}
				else if(selected == 2)
				{
					head = add_in_end(head);
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
				list_show(head);
				break;
			case 4:
				head = sorting_list(head);
				break;
			case 5:
				head = reverse_list(head);
				break;
			case 6:
				printf("\nYou want to remove an item from head, tail or specific item?\n");
				printf("1 - Head\n");
				printf("2 - Tail\n");
				printf("3 - Specific item\n");
				int selected2;
				scanf("%d", &selected2);
				if (selected2 == 1)
				{
					head = rem(head);
					break;
				}
				else if (selected2 == 2)
				{
					rem_from_tail(head);
					break;
				}
				else if (selected2 == 3)
				{
					int item;
					printf("Enter the item you want to remove: ");
					scanf("%d", &item);
					rem_selected_node(head, item);
					break;
				}
				else
				{
					printf("Enter a valid value!");
					break;
				}
			case 7:
				exit(0);
		}
	}
	return 0;
}

//Initialization of linked list
NODE* initList(NODE *head)
{
	return NULL;
}

//function to insert in list's head
NODE* add(NODE *head)
{
	NODE *current;
	int value;
	scanf("%d", &value);
	current = (NODE*) malloc(sizeof(NODE));
	current->item = value;
	//The new NODE turns into the list head
	current->next = head;
	return current;
}

//Function to insert an item on the list's tail
NODE* add_in_end(NODE *head) 
{ 
	int value;
	NODE *current = head;
	printf("Put the value to insert:\n");
	scanf("%d", &value);
    //allocate node
    NODE *new_node = (NODE*) malloc(sizeof(NODE)); 
    new_node->item = value;
    new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		return head;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
    return head;     
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
			if (current->item == wanted)
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

//Function to search/go through the list elements
void list_show(NODE *head)
{
	NODE *current = head;
	int loop = 0;
	if (head == NULL)
	{
		printf("\nEmpty list!\n");
	}
	else
	{
		while(current != NULL)
		{
			printf("\nList item #%d: %d\n", loop, current->item);
			//The actual NODE receives the next NODE pointer
			current = current->next;
			loop += 1;
		}
	}
}

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

//Function to reverse the linked list
NODE* reverse_list(NODE *head) 
{ 
    NODE *prev = NULL; 
    NODE *current = head; 
    NODE *next = NULL; 
    while (current != NULL) { 
        //Store next 
        next = current->next; 
        //Reverse current node's pointer 
        current->next = prev; 
        //Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    head = prev; 
    return head;
}

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
	while (penultimate_node->next->next != NULL)
	{
		penultimate_node = penultimate_node->next;
	}
	free(penultimate_node->next);
	penultimate_node->next = NULL;
	return head;
}

void rem_selected_node(NODE* head, int item)
{
	//Save head pointer
	NODE* aux = head, *previous;

	//The key wanted is in head
	if (aux != NULL && aux->item == item)
	{
		head = aux->next;
		free(aux);
		return;
	}

	//Now search for the wanted key to be deleted
	//Ever saving up the previous node
	while (aux != NULL && aux->item != item)
	{
		previous = aux;
		aux = aux->next;
	}
	if (aux == NULL)//Item wasn't found
	{
		return;
	}
	previous->next = aux->next;//The node is unlinked from list
	free(aux);
}