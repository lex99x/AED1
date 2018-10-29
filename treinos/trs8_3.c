// Enunciado
// Em uma série S estão registradas Quáduplas t, formadas por operação, curso, matricula e nota,
// de candidatos que realizaram um exame de seleção para uma universidade. Durante um período de
// matricula os candidatos podem indicar para que cursos eles irão concorrer com a nota obtida.
// Existem três chamadas nas quais os candidatos podem indicar a sua opção de curso.
// Ao optar(O) por um curso o candidato deve, quando for o caso, registrar a sua desistência(D)
// de outro curso que ele tenha se matriculado.
// Escreva um programa que lê S e a armazene em memória. Ao final da leitura de S seu programa
// deve imprimir todas as quáduplas armazenadas, agrupadas por operação, primeiro as Desistências
// depois as Opções. Considere que:
// Operação é do Tipo Char, e as demais informações são inteiros;
// A série S é encerrada quando um valor ‘F’ for lido para a operação.
// Exemplo de Entrada
// O 1 6397178 97988
// O 1 2541566 85956
// O 1 5470748 58625
// D 0 7617376 46355
// O 1 2426105 52754
// D 0 7403147 27916
// D 0 5567461 3250
// D 0 7118734 41291
// O 1 3549123 64113
// O 1 3546710 55758
// F
// Exemplo de Saída
// D 0 7617376 46355
// D 0 7403147 27916
// D 0 5567461 3250
// D 0 7118734 41291
// O 1 6397178 97988
// O 1 2541566 85956
// O 1 5470748 58625
// O 1 2426105 52754
// O 1 3549123 64113
// O 1 3546710 55758

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

typedef struct{

	char op;
	int curso, matricula, nota;

} Candidato;

void imprimirCandidato(void* info, Tipo tipo){

	Candidato* candidato = (Candidato*) info;

	printf("%c %d %d %d\n", candidato -> op, candidato -> curso, candidato -> matricula, candidato -> nota);

}

int main(void){

	Lista* listaO = criarLista();
	Lista* listaD = criarLista();

	Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));

	scanf(" %c", &candidato -> op);

	while(candidato -> op != 'F'){

		scanf("%d %d %d", &candidato -> curso, &candidato -> matricula, &candidato -> nota);

		if(candidato -> op == 'O') inserirFinalLista(listaO, candidato, STRUCT);
		else inserirFinalLista(listaD, candidato, STRUCT);

		candidato = (Candidato*) malloc(sizeof(Candidato));

		scanf(" %c", &candidato -> op);

	}

	free(candidato);

	imprimirLista(listaD, imprimirCandidato);
	imprimirLista(listaO, imprimirCandidato);

	return 0;

}