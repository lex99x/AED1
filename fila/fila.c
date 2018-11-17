#include <stdlib.h>
#include "../lista/lista.h"
#include "fila.h"

struct fila{

	int ocup;
	Lista* lista;

};

Fila* criarFila(void){

	Fila* fila = (Fila*) malloc(sizeof(Fila));

	fila -> ocup = 0;
	fila -> lista = criarLista();

	return fila;

}

void enfileirar(Fila* fila, void* info){

	inserirFinalLista(fila -> lista, info);

	fila -> ocup++;

}

void* desenfileirar(Fila* fila){

	void* info = removerInicioLista(fila -> lista);

	if(info != NULL) fila -> ocup--;

	return info;

}

void* primeiro(Fila* fila){

	return fila -> lista -> inicio -> info;

}

void* ultimo(Fila* fila){

	return fila -> lista -> final -> info;

}

int comprimento(Fila* fila){

	return fila -> ocup;

}

short vazia(Fila* fila){

	return fila -> ocup == 0;

}