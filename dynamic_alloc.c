#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *val;
	int size, n = 0;

	printf("Digite o tamanho do Vetor: \n");
	scanf("%d", &size);

	int vector[size];
	while (1)
	{
		val = (int *) malloc(size * sizeof(int));//Function malloc returns a void pointer, conversion is necessary malloc(lenght of bytes allocated)
		free(val); //Function free needs a pointer to the mem allocation to desalocate
		printf("Let it go!\n");
	}
	return 0;
}