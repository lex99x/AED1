#include <stdlib.h>
#include "../lista/lista.h"
#include "pilha.h"

struct pilha{

	Lista* lista;

};

Pilha* criarPilha(void){

	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

	pilha -> lista = criarLista();

	return pilha;

}

void empilhar(Pilha* pilha, void* info){

	inserirInicioLista(pilha -> lista, info);

}

void* desempilhar(Pilha* pilha){

	return removerInicioLista(pilha -> lista);

}

int alturaPilha(Pilha* pilha){

	return tamanhoLista(pilha -> lista);

}

void* topoPilha(Pilha* pilha){

	return inicioLista(pilha -> lista);

}

short pilhaVazia(Pilha* pilha){

	return listaVazia(pilha -> lista);

}