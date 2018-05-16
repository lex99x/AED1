#include <stdlib.h>
#include "lista.h"

Lista* lista_cria(void){;

    return NULL;

}

void lista_insere(Lista** lista, int num){

    Lista* l = (Lista*) malloc(sizeof(Lista));

    l -> num = num;
    l -> prox = *lista;

    *lista = l;

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

    for(Lista* l = lista; l != NULL; l = l -> prox){

        printf("%d ", l -> num);

    }

}