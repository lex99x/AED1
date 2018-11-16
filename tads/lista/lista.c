#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct elemento Elemento;

struct elemento{

	void* info;
	Elemento* ant;
	Elemento* prox;

};

Elemento* criarElemento(void* info){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> info = info;

	return elemento;

}

struct lista{

	int tam;
	Elemento* inicio;
	Elemento* final;

};

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> tam = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

void inserirOrdenadoLista(Lista* lista, void* info, Comparador comparador){

	Elemento* ant = NULL;
	Elemento* aux = lista -> inicio;

	while(aux != NULL && comparador(info, aux -> info) >= 0){

		ant = aux;
		aux = aux -> prox;

	}

	if(ant != NULL && aux != NULL){

		Elemento* elemento = criarElemento(info);

		ant -> prox = elemento;
		elemento -> ant = ant;
		elemento -> prox = aux;
		aux -> ant = elemento;

		lista -> tam++;

	}else if(ant == NULL){

		inserirInicioLista(lista, info);

	}else{

		inserirFinalLista(lista, info);

	}

}

void inserirInicioLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> tam == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
	lista -> tam++;

}

void inserirFinalLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = lista -> final;
	elemento -> prox = NULL;

	if(lista -> tam == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
	lista -> tam++;

}

void* removerInicioLista(Lista* lista){

	void* info = NULL;

	if(lista -> tam > 0){

		Elemento* prox = lista -> inicio -> prox;
		info = lista -> inicio -> info;
		free(lista -> inicio);
		lista -> inicio = prox;

		if(lista -> inicio == NULL) lista -> final = NULL;
		else prox -> ant = NULL;

		lista -> tam--;

	}

	return info;

}

void* removerFinalLista(Lista* lista){

	void* info = NULL;

	if(lista -> tam > 0){

		Elemento* ant = lista -> final -> ant;
		info = lista -> final -> info;
		free(lista -> final);
		lista -> final = ant;

		if(lista -> final == NULL) lista -> inicio = NULL;
		else ant -> prox = NULL;

		lista -> tam--;

	}

	return info;

}

void percorrerLista(Lista* lista, Callback callback){

	if(lista -> tam > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			callback(elemento -> info);
			elemento = elemento -> prox;

		}

	}

}

int tamanhoLista(Lista* lista){

	return lista -> tam;

}
