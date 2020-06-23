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

//Quick sort ordenation fucntion
void quick_sort(int *v, int left, int right)
{
	int i, j, x, y;
	i = left;
	j = right;
	x = v[(left + right) / 2];
	//While left and right don't cross
	while (i <= j)
	{
		//Searching the first higher value in the left
		while (v[i] < x && i < right)
		{
			i++;
		}
		//Searching the first higher value in the right
		while (v[j] > x && j > left)
		{
			j--;
		}
		//Swaping vallues
		if (i <= j)
		{
			swap(v, i, j);//Swap function call
			i++;
			j--;
		}
	}
	//Percouring the left side of vector
	if (j > left)
	{
		quick_sort(v, left, j);//Recursive call of quick_sort function going to left
	}
	//Percouring the left side of vector
	if (i < right)
	{
		quick_sort(v, i, right);//Recursive call of quick_sort function going to right
	}
}

int main()
{
	int *v, size;
	printf("Vector lenght: \n");
	scanf("%d", &size);
	v = (int *) malloc(size * sizeof(int));//Allocation 
	//Reading values
	for (int i = 0; i < size; ++i)
	{
		printf("Enter value to the position %d: \n", i + 1);
		scanf("%d", &v[i]);
	}
	//Order values
	quick_sort(v, 0, size - 1);
	//Showing ordered values
	for (int i = 0; i < size; ++i)
	{
		printf("Value in the #%d position: %d\n", i + 1, v[i]);
	}
	free(v);
	return 0;
}