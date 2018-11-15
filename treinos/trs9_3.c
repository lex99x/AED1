// Enunciado
// Filas para Simulação do Controle de Pista de Decolagem de Aviões
// Escreva um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto.
// Implemente um fila utilizando ponteiros e alocação dinâmica para armazenar os dados.
// Considere que cada avião possui um nome formado pelo identificador da companhia aérea
// (3 caracteres), seguido de um espaço, seguido de um número (1 a 999)
// que indica o avião, dentro da companhia.
// Neste programa, o usuário deve ser capaz de realizar as seguintes operações:
// 1) Q (lista a quantidade de aviões aguardando na fila de decolagem);
// 2) D (autoriza a decolagem do primeiro avião da fila);
// 3) A c n (adiciona um avião da companhia c e identificador n à fila de espera);
// 4) L (lista os nomes de todos os aviões que estão na fila de espera);
// 5) P (imprime o nome do primeiro avião da fila);
// 6) S (limpa a fila e sai do programa).
// Dicas
// Entrada
// A AZU 1
// A GOL 1
// A TAM 45
// A AAL 21
// Q
// P
// D
// P
// L
// S
// Saída
// 4
// AZU 1
// GOL 1
// GOL 1
// TAM 45
// AAL 21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento Elemento;

struct elemento{

	void* info;
	Elemento* ant;
	Elemento* prox;

};

typedef struct{

	int quant;
	Elemento* inicio;
	Elemento* final;

} Lista;

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

void inserirFinalLista(Lista* lista, void* num){

	Elemento* elemento = criarElemento(num);

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

typedef void (*Imprimir)(void*); void imprimirLista(Lista* lista, Imprimir imprimir);

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info);

			elemento = elemento -> prox;

		}

	}

}

typedef struct fila Fila;

struct fila{

	int ocup;
	Lista* lista;

};

Fila* criarFila(void){

	Fila* fila = (Fila*) malloc(sizeof(Fila));

	fila -> ocup = 0;
	fila -> lista = criarLista();

	return fila;

}

void enfileirar(Fila* fila, void* num){

	inserirFinalLista(fila -> lista, num);

	fila -> ocup++;

}

void* desenfileirar(Fila* fila){

	void* num = removerInicioLista(fila -> lista);

	if(num != NULL) fila -> ocup--;

	return num;

}

void* primeiro(Fila* fila){

	return fila -> lista -> inicio -> info;

}

void* ultimo(Fila* fila){

	return fila -> lista -> final -> info;

}

int comprimento(Fila* fila){

	return fila -> ocup;

}

short vazia(Fila* fila){

	return fila -> ocup == 0;

}

typedef void(*Imprimir)(void*);

void imprimirFila(Fila* fila, Imprimir imprimir){

	imprimirLista(fila -> lista, imprimir);

}

typedef struct{

	char companhia[4];
	int id;

} Aviao;

void imprimirAviao(void* info){

	Aviao* aviao = (Aviao*) info;

	printf("%s %d\n", aviao -> companhia, aviao -> id);

}

int main(void){

	Fila* fila = criarFila();
	Aviao* aviao = (Aviao*) malloc(sizeof(Aviao));

	char operacao;

	scanf(" %c", &operacao);

	while(operacao != 'S'){

		switch(operacao){

			case 'A':

				scanf(" %s %d", aviao -> companhia, &aviao -> id);

				enfileirar(fila, aviao);

				aviao = (Aviao*) malloc(sizeof(Aviao));

			break;

			case 'Q': printf("%d\n", comprimento(fila)); break;

			case 'D': desenfileirar(fila); break;

			case 'P':

				aviao = (Aviao*) primeiro(fila);

				printf("%s %d\n", aviao -> companhia, aviao -> id);

			break;

			case 'L': imprimirFila(fila, imprimirAviao); break;


		}

		scanf(" %c", &operacao);

	}

	free(aviao);

	int cont = 0;

	while(cont < comprimento(fila)){

		aviao = (Aviao*) desenfileirar(fila);

		free(aviao);

		cont++;

	}

	return 0;

}