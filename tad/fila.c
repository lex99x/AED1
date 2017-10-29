#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* fila_cria(void){

    Fila* fila = malloc(sizeof(Fila));

    fila -> ini = fila -> fim = NULL;

    return fila;

}

void enfileirar(Fila* fila, char action, int val){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista -> action = action;
    lista -> val = val;
    lista -> prox = NULL;

    if(fila -> fim == NULL){

        fila -> ini = lista;

    }else{

        fila -> fim -> prox = lista;

    }

    fila -> fim = lista;

}

void desenfileirar(Fila* fila){

    Lista* temp = fila -> ini;

    fila -> ini = fila -> ini -> prox;

    if(fila -> ini == NULL){

        fila -> fim = NULL;

    }

    free(temp);

}