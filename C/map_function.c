#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Cube function
int cube(int y)
{
	return y * y * y;
}

//Square function
int square(int x)
{
	return x * x;
}

//Factorial function
int factorial(int n)
{
	int fat = 1;
	while (n != 1)
	{
		fat *= n;
		n--;
	}
	return fat;
}

//The map function receives another function as his parameter
int map(int (*func)(int x), int *ptr, int size)
{
	int i;
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = (*func)(ptr[i]);
	}
}

int main()
{
	int *ptr, size, i;

	printf("Enter the size allocated:\n");
	scanf("%d", &size);

	ptr = (int *) malloc(size * sizeof(int));//Dynamic allocation

	for (i = 0; i < size; ++i)
	{
		printf("Enter a number to position %d: \n", i + 1);
		scanf("%d", &ptr[i]);
	}

	map(factorial, ptr, size);//Calling map function sending the function that will be used as parameter
	printf("Factorial results\n");
	for (i = 0; i < size; ++i)
	{
		printf("Position %d: %d\n", i + 1, ptr[i]);//Showing results of map function
	}

	map(square, ptr, size);//Calling map function sending the function that will be used as parameter
	printf("Square results\n");
	for (i = 0; i < size; ++i)
	{
		printf("Position %d: %d\n", i + 1, ptr[i]);//Showing results of map function
	}

	map(cube, ptr, size);//Calling map function sending the function that will be used as parameter
	printf("Cube results\n");
	for (i = 0; i < size; ++i)
	{
		printf("Position %d: %d\n", i + 1, ptr[i]);//Showing results of map function
	}

	free(ptr);//Deallocating Memory

	return 0;
}