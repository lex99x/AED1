#include "array.h"
#include <stdio.h>

int main(void){

	Array* array = criar(10);

	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	array -> agreg = vet;
	array -> ocup = 10;

	imprimir(array);

	return 0;

}