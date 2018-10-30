#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam;
	else array -> tam = 1;

	array -> vet = (void**) malloc(array -> tam * sizeof(void*));
	array -> ocup = 0;

	return array;

}

void inserirArray(Array* array, void* info){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> vet = (void**) realloc(array -> vet, array -> tam * sizeof(void*));

	}

	array -> vet[array -> ocup] = info;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos >= 0 && pos <= array -> ocup) return array -> vet[pos];
	else return NULL;

}

void imprimirArray(Array* array, Imprimir imprimir){

	int cont = 0;

	while(cont < array -> ocup){

		void* info = acessarArray(array, cont);

		imprimir(info);

		cont++;

	}

}