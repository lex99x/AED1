#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> quant = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

Elemento* criarElemento(void* info, Tipo tipo){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> tipo = tipo;
	elemento -> info = info;

	return elemento;

}

void inserirInicioLista(Lista* lista, void* info, Tipo tipo){

	Elemento* elemento = criarElemento(info, tipo);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> quant == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
	lista -> quant++;

}

void inserirFinalLista(Lista* lista, void* info, Tipo tipo){

	Elemento* elemento = criarElemento(info, tipo);

	elemento -> ant = lista -> final;
	elemento -> prox = NULL;

	if(lista -> quant == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
	lista -> quant++;

}

void inserirOrdenadoLista(Lista* lista, void* info, Tipo tipo, Converter converter){

	switch(lista -> tipo){

		case INT: int info = *((int*) info), ; break;
		case DOUBLE: double info = *((double*) info); break;

	}

	Elemento* elemento = lista -> inicio;
	Elemento* ant = NULL;

	while(elemento != NULL && *elemento -> info < converter(info)){

		ant = elemento;
		elemento = elemento -> prox;

	}

	elemento = criarElemento(info, tipo);

	if(ant == NULL){

		elemento -> prox = lista -> inicio;
		lista -> inicio = elemento;

	}else{

		elemento -> prox = ant -> prox;
		ant -> prox = elemento;

	}

}

void* removerInicioLista(Lista* lista){

	void* info = NULL;

	if(lista -> quant > 0){

		Elemento* prox = lista -> inicio -> prox;
		info = lista -> inicio -> info;
		free(lista -> inicio);
		lista -> inicio = prox;

		if(lista -> inicio == NULL) lista -> final = NULL;
		else prox -> ant = NULL;

		lista -> quant--;

	}

	return info;

}

void* removerFinalLista(Lista* lista){

	void* info = NULL;

	if(lista -> quant > 0){

		Elemento* ant = lista -> final -> ant;
		info = lista -> final -> info;
		free(lista -> final);
		lista -> final = ant;

		if(lista -> final == NULL) lista -> inicio = NULL;
		else ant -> prox = NULL;

		lista -> quant--;

	}

	return info;

}

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info, elemento -> tipo);
			
			elemento = elemento -> prox;

		}

		printf("\n");

	}

}