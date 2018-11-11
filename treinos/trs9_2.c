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

void inserirInicioLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> quant == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
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

typedef struct pilha Pilha;

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

typedef struct{

	double latitude;
	double longitude;
	double temperatura;
	int idSensor;

} Medida;

int main(void){

	Pilha* pilha = criarPilha();
	Medida* medida = (Medida*) malloc(sizeof(Medida));
	int* num = (int*) malloc(sizeof(int));

	char tipo[15], operacao;

	scanf(" %s", tipo);
	scanf(" %c", &operacao);

	while(operacao != 'X'){

		switch(operacao){

			case 'E':

				if(!strcmp(tipo, "inteira")){

					scanf("%d", num);

					empilhar(pilha, num);

					num = (int*) malloc(sizeof(int));

				}else{

					scanf("%lf %lf %lf %d", &medida -> latitude, &medida -> longitude, &medida -> temperatura, &medida -> idSensor);

					empilhar(pilha, medida);

					medida = (Medida*) malloc(sizeof(Medida));

				}

			break;

			case 'D':

				if(!strcmp(tipo, "inteira")){

					num = (int*) desempilhar(pilha);

					printf("%d\n", *num);

				}else{

					medida = (Medida*) desempilhar(pilha);

					printf("%.3lf %.3lf %.3lf %d\n", medida -> latitude, medida -> longitude, medida -> temperatura, medida -> idSensor);

				}

			break;

			case 'T':

				if(!strcmp(tipo, "inteira")){

					num = (int*) topo(pilha);

					printf("%d\n", *num);

				}else{

					medida = (Medida*) topo(pilha);

					printf("%.3lf %.3lf %.3lf %d\n", medida -> latitude, medida -> longitude, medida -> temperatura, medida -> idSensor);

				}

			break;

			case 'A': printf("%d\n", altura(pilha)); break;

			case 'V': if(vazia(pilha)) printf("verdadeiro\n"); else printf("falso\n");

		}

		scanf(" %c", &operacao);

	}

	free(medida); free(num);

	return 0;

}