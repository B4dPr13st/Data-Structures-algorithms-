#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int even(int z)
{
	return (z % 2 == 0);
}

int odd(int y)
{
	return (y % 2 != 0);
}

//The filter function receives another function as his parameter
int filter(int (*func)(int x), int *ptr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if ((*func)(ptr[i]))
		{
			printf("Position %d: %d\n", ptr[i]);
		}
	}
	printf("\n");
}

int main()
{
	int *ptr, size;

	printf("Enter the amount of memory that will be allocated:\n");
	scanf("%d", &size);

	ptr = (int *) malloc(size * sizeof(int));//Allocating memory

	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &ptr[i]);
	}

	filter(even, ptr, size);//Calling the filter function using even function as his parameter
	filter(odd, ptr, size);//Calling the filter function using odd function as his parameter

	free(ptr);//Deallocating Memory

	return 0;
}