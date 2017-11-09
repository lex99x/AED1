#include <stdlib.h>
#include "fila.h"

Fila* fila_criar(void){

    // Aloca e inicializa nova fila com ponteiros nulos

    Fila* fila = malloc(sizeof(Fila));

    fila -> ini = fila -> fim = NULL;

    return fila;

}

void fila_inserir(Fila* fila, void* info){

    // Aloca e inicializa nova lista com a info passada

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista -> info = info;
    lista -> prox = NULL;

    // Verifica se a lista está vazia

    if(fila -> fim == NULL){

        // Atribue a nova lista ao início da fila

        fila -> ini = lista;

    }else{

        // Linka o fim da fila à nova lista

        fila -> fim -> prox = lista;

    }

    // Atualiza o fim da fala para a nova lista

    fila -> fim = lista;

}

void fila_remover(Fila* fila){

    // Variável auxiliar com o endereço do início da fila

    Lista* aux = fila -> ini;

    // Atualiza o início da fila para o elemento seguinte ao início desenfileirado

    fila -> ini = fila -> ini -> prox;

    // Verifica se a lista ficou vazia

    if (fila -> ini == NULL) fila -> fim = NULL;

    // Remove início desenfileirado da memória

    free(aux);

}

void* fila_inicio(Fila* fila){

    return fila -> ini -> info;

}

void* fila_fim(Fila* fila){

    return fila -> fim -> info;

}