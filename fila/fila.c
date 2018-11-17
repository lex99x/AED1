#include <stdlib.h>
#include "../lista/lista.h"
#include "fila.h"

struct fila{

	Lista* lista;

};

Fila* criarFila(void){

	Fila* fila = (Fila*) malloc(sizeof(Fila));

	fila -> lista = criarLista();

	return fila;

}

void enfileirar(Fila* fila, void* info){

	inserirFinalLista(fila -> lista, info);

}

void* desenfileirar(Fila* fila){

	return removerInicioLista(fila -> lista);

}

void* primeiroFila(Fila* fila){

	return inicioLista(fila -> lista);

}

void* ultimoFila(Fila* fila){

	return finalLista(fila -> lista);

}

int comprimentoFila(Fila* fila){

	return tamanhoLista(fila -> lista);

}

short filaVazia(Fila* fila){

	return listaVazia(fila -> lista);

}