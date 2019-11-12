#include <stdio.h>
#include <stdlib.h>

//Swap function
void swap(int *v, int actual, int next)
{
	int aux;
	//Swaping values
	aux = v[actual];
	v[actual] = v[next];
	v[next] = aux;
}

//Bubblesort function
void bubblesort(int *v, int j, int i)
{
	for (j -= 1; j >= 0 ; j--)//Decreasement of vector lenght
	{
		for (i = 0; i < j; ++i)//Percouring vector
		{
			if (v[i] >= v[i + 1])
			{
				swap(v, i, i + 1);//Swap function call
			}
		}
	}
}

int main()
{
	int *v, size;
	printf("Vector lenght:\n");
	scanf("%d", &size);
	v = (int *) malloc(size * sizeof(int));//Dynamic Allocation
	for (int i = 0; i < size; ++i)//Scanning values
	{
		printf("Enter value to the position %d: \n", i + 1);
		scanf("%d", &v[i]);
	}
	bubblesort(v, size, 0);//Calling bubblesort function
	for (int i = 0; i < size; ++i)//Showing values
	{
		printf("Value in the position %d: %d\n", i + 1, v[i]);
	}
	free(v);
	return 0;
}