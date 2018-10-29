// Enunciado
// Faça um programa que leia duas listas (A e B) de valores numéricos positivos
// ordenados (a leitura de cada lista termina quando o valor lido for negativo),
// coloque ambas as listas em listas encadeadas, imprima Uma lista contendo os
// elementos de A e B intercalados sob as seguintes condições:
// os valores na lista resultante devem estar ordenados;
// Não basta imprimir, a lista encadeada correspondente deve ser criada.
// Exemplo de Entrada
// 2 4 10 15 -1
// 1 3 9  14 -2
// Exemplo de Saída
// 1 2 3 4 9 10 14 15

#include <stdio.h>
#include <stdlib.h>

typedef enum{

	INT,
	CHAR,
	LONG,
	FLOAT,
	DOUBLE,
	STRUCT,
	VOID

} Tipo;

typedef struct elemento Elemento;

struct elemento{

	Tipo tipo;
	void* info;
	Elemento* ant;
	Elemento* prox;

};

typedef struct{

	int quant;
	Tipo tipo;
	Elemento* inicio;
	Elemento* final;

} Lista;

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

void inserirOrdenadoLista(Lista* lista, void* info, Tipo tipo){

	Elemento* elemento = lista -> inicio;
	Elemento* ant = NULL;

	while(elemento != NULL && (*((int*) elemento -> info) < *((int*) info))){

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

	}else printf("NÃO É POSSÍVEL REMOVER INÍCIO DE LISTA VAZIA!\n");

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

	}else printf("NÃO É POSSÍVEL REMOVER FINAL DE LISTA VAZIA!\n");

	return info;

}

typedef void (*Imprimir)(void*, Tipo);

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info, elemento -> tipo);

			elemento = elemento -> prox;

		}

	}else printf("NÃO É POSSÍVEL IMPRIMIR LISTA VAZIA!");

}

void imprimirInfo(void* info, Tipo tipo){

	printf("%d ", *((int*) info));

}

int main(void){

	Lista* listaC = criarLista();

	int* val = (int*) malloc(sizeof(int));

	scanf("%d", val);

	while(*val >= 0){

		inserirOrdenadoLista(listaC, val, INT);

		val = (int*) malloc(sizeof(int));

		scanf("%d", val);

	}

	scanf("%d", val);

	while(*val >= 0){

		inserirOrdenadoLista(listaC, val, INT);

		val = (int*) malloc(sizeof(int));

		scanf("%d", val);

	}

	imprimirLista(listaC, imprimirInfo);

	return 0;

}