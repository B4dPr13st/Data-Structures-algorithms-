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

	val = (int *) malloc(size * sizeof(int));//Function malloc returns a void pointer, conversion is necessary malloc(lenght of bytes allocated)
	
	for (int i = 0; i < size; ++i)
	{
		printf("Digite um valor para a posição %d: \n", i + 1);
		scanf("%d", &val[i]);
	}
	for (i = 0; i < size; ++i)
	{
		printf("Valor na posição %d: %d\n", i + 1, val[i]);
	}

	free(val); //Function free needs a pointer to the mem allocation to desalocate

	return 0;
}
