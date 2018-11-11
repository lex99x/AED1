// Enunciado
// Implemente as operações básicas para manipulação de uma fila, que incluem:
// Criar
// Enfileirar (E)
// Desenfileirar (D)
// Primeiro (P)
// Ultimo (U)
// Comprimento (C)
// Vazia (V)
// Para testar a sua implementação das operações uma Sequência S será instânciada.
// Cada instância será de um tipo de dados que precisa ser armazenado em sua fila.
// A sequência S será seguida por uma sequência T com as operações que precisam
// ser realizadas com a fila.
// Dois tipos são instanciados em S: inteiro e double. Os valores do tipo double
// precisam ser impressos com 3(três) casas decimais.
// Você pode usar as suas implementações neutralizadas das E.D básicas (lista e vetor dinâmico).
// O resultado da operação V deve ser expresso por uma das seguintes mensagens: falso ou verdadeiro.
// Exemplo de Entrada
// inteiro
// E 10
// E 5
// E 100
// D
// D
// C
// E -10
// P
// U
// C
// V
// X
// Exemplo de Saída
// 10
// 5
// 1
// 100
// -10
// 2
// falso

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

int main(void){

	Fila* fila = criarFila();
	double* num = (double*) malloc(sizeof(double));

	char tipo[10], operacao;

	scanf(" %s", tipo);
	scanf(" %c", &operacao);

	while(operacao != 'X'){

		switch(operacao){

			case 'E':

				scanf("%lf", num);

				enfileirar(fila, num);

				num = (double*) malloc(sizeof(double));

			break;

			case 'D':

				num = (double*) desenfileirar(fila);

				if(!strcmp(tipo, "inteiro")) printf("%d\n", (int) *num); else printf("%.3lf\n", *num);

			break;

			case 'P':

				num = (double*) primeiro(fila);

				if(!strcmp(tipo, "inteiro")) printf("%d\n", (int) *num); else printf("%.3lf\n", *num);

			break;

			case 'U':

				num = (double*) ultimo(fila);

				if(!strcmp(tipo, "inteiro")) printf("%d\n", (int) *num); else printf("%.3lf\n", *num);

			break;

			case 'C': printf("%d\n", comprimento(fila)); break;

			case 'V': if(vazia(fila)) printf("verdadeiro\n"); else printf("falso\n");

		}

		scanf(" %c", &operacao);

	}

	free(num);

	return 0;

}