#include "pilha.h"

struct lista{

    char action;
    int val;
    struct lista* prox;

};

struct fila{

    Lista* ini;
    Lista* fim;

};

typedef struct lista Lista;
typedef struct fila Fila;

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