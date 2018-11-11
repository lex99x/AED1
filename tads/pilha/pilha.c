#include <stdlib.h>
#include "../lista/lista.h"
#include "pilha.h"

struct pilha{

	int ocup;
	Lista* lista;

};

Pilha* criarPilha(void){

	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

	pilha -> ocup = 0;
	pilha -> lista = criarLista();

	return pilha;

}

void empilhar(Pilha* pilha, void* info){

	inserirInicioLista(pilha -> lista, info);

	pilha -> ocup++;

}

void* desempilhar(Pilha* pilha){

	void* info = removerInicioLista(pilha -> lista);

	if(info != NULL) pilha -> ocup--;

	return info;

}

int altura(Pilha* pilha){

	return pilha -> ocup;

}

void* topo(Pilha* pilha){

	return pilha -> lista -> inicio -> info;

}

short vazia(Pilha* pilha){

	return pilha -> ocup == 0;

}