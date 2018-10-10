#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam; else array -> tam = 1;

	array -> ocup = 0;
	array -> agreg = malloc(tam * sizeof(void*));

	return array;

}

void inserirArray(Array* array, void* elem){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> agreg = realloc(array -> agreg, array -> tam * sizeof(void*));

	}

	array -> agreg[array -> ocup] = elem;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos < 0 || pos > array -> ocup) exit(0);

	return array -> agreg[pos];

}

void liberarArray(Array* array){

	free(array -> agreg);
	free(array);

}