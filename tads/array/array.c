#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array.h"

struct array{

	int tam;
	int ocup;
	void** vet;

};

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam;
	else array -> tam = 1;

	array -> ocup = 0;
	array -> vet = malloc(array -> tam * sizeof(void*));
	memset(array -> vet,'\0', array -> tam * sizeof(void*));

	return array;

}

void inserirArray(Array* array, void* info, int pos){

	if(pos >= array -> tam){

		int ant = array -> tam;
		int k = ceil(log2(pos));
		array -> tam = pow(2, k) + 1;
		array -> vet = realloc(array -> vet, array -> tam * sizeof(void*));
		memset(array -> vet + ant, '\0', (array -> tam - ant) * sizeof(void*));

	}

	array -> vet[pos] = info;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos >= 0 && pos < array -> tam) return array -> vet[pos];
	else return NULL;

}

int tamanhoArray(Array* array){

	return array -> ocup;

}