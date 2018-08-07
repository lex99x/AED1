#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_cria(void){

	return NULL;

}

Lista* lista_insere(Lista** lista, int num){

	Lista* l = (Lista*) malloc(sizeof(Lista));

	l -> num = num;
	l -> prox = *lista;
	*lista = l;

	return l;

}

void lista_libera(Lista* lista){

	Lista* l = lista;
	Lista* prox = NULL;

	while(l != NULL){

		prox = l -> prox;
		free(l);
		l = prox;

	}

}

void lista_imprime(Lista* lista){

	if(!lista_vazia(lista)){

		for(Lista* l = lista; l != NULL; l = l -> prox){

			printf("%d ", l -> num);

		}

	}else{

		printf("Lista vazia!");

	}

	printf("\n");

}

short lista_vazia(Lista* lista){

	return lista == NULL;

}

Lista* lista_anterior(Lista* lista, Lista* pont){

	Lista* ant = NULL;

	if(!lista_vazia(lista)){

		for(Lista* l = lista; l != pont; l = l -> prox){

			if (l -> prox == pont) ant = l;

		}

	}

	return ant;

	// Solução recursiva

	// if(lista_vazia(lista))
	//     return lista;
	// else if(lista -> prox == pont)
	//     return lista;
	// else
	//     return lista_anterior(lista -> prox, pont);

}

void lista_retira(Lista** lista, Lista* pont){

	Lista* prox = pont -> prox;

	if(!lista_vazia(*lista) && pont != NULL){

		if(*lista != pont){ // Caso geral

			Lista* ant = lista_anterior(*lista, pont);
			ant -> prox = prox;
			free(pont);

		}else{ // Caso de exceção, onde o elemento a ser retirado é o primeiro da lista

			*lista = prox;
			free(pont);

		}

	}else{

		printf("Lista e/ou endereço de memória inválido(s)!\n");

	}

}