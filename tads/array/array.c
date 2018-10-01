#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array* criar(int tam){

	Array* array = (Array*) malloc(sizeof(Array));
	array -> tam = tam;
	array -> ocup = 0;
	array -> agreg = (int*) malloc(sizeof(int) * tam);

	return array;

}

void inserir(Array* array, int num){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> agreg = (int*) realloc(array -> agreg, sizeof(int) * array -> tam);

	}

	array -> agreg[array -> ocup] = num;
	array -> ocup++;

}

int acessar(Array* array, int i){

	if(i < 0 || i > array -> ocup) exit(0);

	return array -> agreg[i];

}

void imprimir(Array* array){

	for(int i = 0; i < array -> ocup; i++) printf("%d ", array -> agreg[i]); printf("\n");

}

void liberar(Array* array){

	free(array -> agreg);
	free(array);

}