#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> quant = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

Elemento* criarElemento(void* info){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
	elemento -> info = info;

	return elemento;

}

void inserirInicioLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> quant == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
	lista -> quant++;

}

void inserirFinalLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = lista -> final;
	elemento -> prox = NULL;

	if(lista -> quant == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
	lista -> quant++;

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

// void inserirOrdenadoLista(Lista* lista, void* info){

// 	Elemento* elemento = lista -> inicio;
// 	Elemento* ant = NULL;

// 	while(elemento != NULL && (*((int*) elemento -> info) < *((int*) info))){

// 		ant = elemento;
// 		elemento = elemento -> prox;

// 	}

// 	elemento = criarElemento(info);

// 	if(ant == NULL){

// 		elemento -> prox = lista -> inicio;
// 		lista -> inicio = elemento;

// 	}else{

// 		elemento -> prox = ant -> prox;
// 		ant -> prox = elemento;

// 	}

// 	lista -> quant++;

// }

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info);

			elemento = elemento -> prox;

		}

		printf("\n");

	}

}