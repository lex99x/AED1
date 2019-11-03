// ################ ENUNCIADO ################

// Considerando a questão do Sudoku passada anteriormente, use a estrutura de dados
// pilha para adicionar à solução da questão a funcionalidade 'retroceder jogada',
// tal funcionalidade funciona como o conhecido 'Ctrl+Z', ou seja, enquanto for informado
// o operador 'R' na execução do programa, o mesmo deve desfazer da última até a primeira
// jogada válida registrada, até que não haja mais jogadas para serem desfeitas.
// As novas possíveis saídas adicionadas ao programa devem ser:

// - "JOGADA (linha, coluna, valor) DESFEITA";
// - "NAO HA JOGADAS PARA RETROCEDER".

// Para melhor compreensão, confira o exemplo abaixo.

// Entrada:

// 1 1 2
// 1 3 8
// 1 4 3
// 1 5 1
// 1 6 7
// 1 8 6
// 1 9 5
// 2 1 1
// 2 2 7
// 2 4 6
// 2 5 5
// 2 6 8
// 2 7 2
// 2 8 4
// 2 9 3
// 3 1 6
// 3 5 9
// 3 6 2
// 3 7 1
// 3 9 7
// 4 2 8
// 4 3 6
// 4 4 1
// 4 5 2
// 4 6 3
// 4 8 9
// 4 9 4
// 5 1 5
// 5 3 4
// 5 8 1
// 6 1 9
// 6 2 1
// 6 3 2
// 6 6 4
// 6 7 7
// 6 8 3
// 6 9 8
// 7 1 3
// 7 4 9
// 7 5 8
// 7 8 7
// 7 9 1
// 8 2 9
// 8 3 7
// 8 4 2
// 8 5 4
// 8 6 1
// 8 7 3
// 8 8 5
// 9 1 4
// 9 2 6
// 9 4 7
// 9 8 2
// 9 9 9
// 0
// J 1 2 4
// J 1 7 9
// J 2 3 9
// J 4 1 7
// J 4 7 5
// V
// R
// R
// R
// R
// R
// R
// J 8 1 8
// J 8 9 6
// J 3 4 4
// J 3 8 8
// J 5 2 3
// V
// R
// R
// R
// R
// R
// R
// R
// F

// Saída:

//   1 2 3 4 5 6 7 8 9
// 1 2 * 8 3 1 7 * 6 5
// 2 1 7 * 6 5 8 2 4 3
// 3 6 * * * 9 2 1 * 7
// 4 * 8 6 1 2 3 * 9 4
// 5 5 * 4 * * * * 1 *
// 6 9 1 2 * * 4 7 3 8
// 7 3 * * 9 8 * * 7 1
// 8 * 9 7 2 4 1 3 5 *
// 9 4 6 * 7 * * * 2 9
// JOGADA (1, 2, 4) EFETUADA
// JOGADA (1, 7, 9) EFETUADA
// JOGADA (2, 3, 9) EFETUADA
// JOGADA (4, 1, 7) EFETUADA
// JOGADA (4, 7, 5) EFETUADA
//   1 2 3 4 5 6 7 8 9
// 1 2 4 8 3 1 7 9 6 5
// 2 1 7 9 6 5 8 2 4 3
// 3 6 * * * 9 2 1 * 7
// 4 7 8 6 1 2 3 5 9 4
// 5 5 * 4 * * * * 1 *
// 6 9 1 2 * * 4 7 3 8
// 7 3 * * 9 8 * * 7 1
// 8 * 9 7 2 4 1 3 5 *
// 9 4 6 * 7 * * * 2 9
// JOGADA (4, 7, 5) DESFEITA
// JOGADA (4, 1, 7) DESFEITA
// JOGADA (2, 3, 9) DESFEITA
// JOGADA (1, 7, 9) DESFEITA
// JOGADA (1, 2, 4) DESFEITA
// NAO HA JOGADAS PARA RETROCEDER
// JOGADA (8, 1, 8) EFETUADA
// JOGADA (8, 9, 6) EFETUADA
// JOGADA (3, 4, 4) EFETUADA
// JOGADA (3, 8, 8) EFETUADA
// JOGADA (5, 2, 3) EFETUADA
//   1 2 3 4 5 6 7 8 9
// 1 2 * 8 3 1 7 * 6 5
// 2 1 7 * 6 5 8 2 4 3
// 3 6 * * 4 9 2 1 8 7
// 4 * 8 6 1 2 3 * 9 4
// 5 5 3 4 * * * * 1 *
// 6 9 1 2 * * 4 7 3 8
// 7 3 * * 9 8 * * 7 1
// 8 8 9 7 2 4 1 3 5 6
// 9 4 6 * 7 * * * 2 9
// JOGADA (5, 2, 3) DESFEITA
// JOGADA (3, 8, 8) DESFEITA
// JOGADA (3, 4, 4) DESFEITA
// JOGADA (8, 9, 6) DESFEITA
// JOGADA (8, 1, 8) DESFEITA
// NAO HA JOGADAS PARA RETROCEDER
// NAO HA JOGADAS PARA RETROCEDER
// FIM DE JOGO
//   1 2 3 4 5 6 7 8 9
// 1 2 * 8 3 1 7 * 6 5
// 2 1 7 * 6 5 8 2 4 3
// 3 6 * * * 9 2 1 * 7
// 4 * 8 6 1 2 3 * 9 4
// 5 5 * 4 * * * * 1 *
// 6 9 1 2 * * 4 7 3 8
// 7 3 * * 9 8 * * 7 1
// 8 * 9 7 2 4 1 3 5 *
// 9 4 6 * 7 * * * 2 9

// ################ SOLUÇÃO ################

#include <stdio.h>
#include <stdlib.h>
#define N 9
#define bool unsigned short int

// TADs auxiliares

typedef struct elemento Elemento;

struct elemento{

	void* info;
	Elemento* ant;
	Elemento* prox;

};

Elemento* criarElemento(void* info){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> info = info;

	return elemento;

}

typedef struct lista Lista;

struct lista{

	int tam;
	Elemento* inicio;
	Elemento* final;

};

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> tam = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

void inserirInicioLista(Lista* lista, void* info){

	Elemento* elemento = criarElemento(info);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> tam == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
	lista -> tam++;

}

void* removerInicioLista(Lista* lista){

	void* info = NULL;

	if(lista -> tam > 0){

		Elemento* prox = lista -> inicio -> prox;
		info = lista -> inicio -> info;
		free(lista -> inicio);
		lista -> inicio = prox;

		if(lista -> inicio == NULL) lista -> final = NULL;
		else prox -> ant = NULL;

		lista -> tam--;

	}

	return info;

}

typedef struct pilha Pilha;

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

// Implementação da solução

int sudokuJogo[N][N], sudokuParcial[N][N];

typedef struct{

	int linha, coluna, valor;

} Jogada;

Jogada* criarJogada(int linha, int coluna, int valor){

	Jogada* jogada = (Jogada*) malloc(sizeof(Jogada));

	jogada -> linha = linha;
	jogada -> coluna = coluna;
	jogada -> valor = valor;

	return jogada;

}

bool validarCoordenada(int coordenada){

	return 0 <= coordenada && coordenada <= N - 1;

}

bool validarValor(int valor){

	return 1 <= valor && valor <= N;

}

bool validarPosicaoParcial(int linha, int coluna){

	return sudokuParcial[linha][coluna] == 0;

}

bool validarPosicaoJogo(int linha, int coluna){

	return sudokuJogo[linha][coluna] == 0;

}

bool validarDupla(int linha, int coluna){

	return (

		validarCoordenada(linha) &&
		validarCoordenada(coluna) &&
		validarPosicaoParcial(linha, coluna) &&
		!validarPosicaoJogo(linha, coluna)

	);

}

bool validarHorizontal(int linha, int valor){

	int coluna;

	for(coluna = 0; coluna < N; coluna++){

		if(sudokuJogo[linha][coluna] == valor) return 0;

	}

	return 1;

}

bool validarVertical(int coluna, int valor){

	int linha;

	for(linha = 0; linha < N; linha++){

		if(sudokuJogo[linha][coluna] == valor) return 0;

	}

	return 1;

}

bool validarQuadrante(int linha, int coluna, int valor){

	int origemLinha = 3 * (linha/3), origemColuna = 3 * (coluna/3);

	for(linha = origemLinha; linha < (origemLinha + 3); linha++){

		for(coluna = origemColuna; coluna < (origemColuna + 3); coluna++){

			if(sudokuJogo[linha][coluna] == valor) return 0;

		}

	}

	return 1;

}

bool validarTripla(int linha, int coluna, int valor){

	return (

		validarCoordenada(linha) &&
		validarCoordenada(coluna) &&
		validarValor(valor) &&
		validarPosicaoParcial(linha, coluna) &&
		validarHorizontal(linha, valor) &&
		validarVertical(coluna, valor) &&
		validarQuadrante(linha, coluna, valor)

	);

}

int popularSudokus(void){

	int linha, coluna, valor, cont = 0;

	for(linha = 0; linha < N; linha++){

		for(coluna = 0; coluna < N; coluna++){

			sudokuJogo[linha][coluna] =
			sudokuParcial[linha][coluna] = 0;

		}

	}

	scanf("%d", &linha);

	while(linha != 0){

		scanf("%d %d", &coluna, &valor);

		linha--; coluna--;

		sudokuJogo[linha][coluna] =
		sudokuParcial[linha][coluna] = valor;

		scanf("%d", &linha);

		cont++;

	}

	return cont;

}

void imprimirSudokuJogo(void){

	int linha, coluna;

	printf(" "); for(coluna = 1; coluna <= N; coluna++) printf(" %d", coluna);

	for(linha = 0; linha < N; linha++){

		printf("\n%d", linha + 1);

		for(coluna = 0; coluna < N; coluna++){

			int valor = sudokuJogo[linha][coluna];

			if(valor != 0) printf(" %d", valor); else printf(" *");

		}

	}

	printf("\n");

}

int main(void){

	int quantRegistros = popularSudokus(); char funcao = '\0';

	Jogada* jogada; Pilha* jogadas = criarPilha();

	imprimirSudokuJogo();

	while(funcao != 'F' && quantRegistros < N * N){

		scanf(" %c", &funcao);

		switch(funcao){

			int linha, coluna, valor;

			case 'J':

				scanf("%d %d %d", &linha, &coluna, &valor);

				printf("JOGADA (%d, %d, %d) ", linha, coluna, valor);

				linha--; coluna--;

				if(validarTripla(linha, coluna, valor)){

					sudokuJogo[linha][coluna] = valor;
					quantRegistros++;

					jogada = criarJogada(linha, coluna, valor);

					empilhar(jogadas, jogada);

					printf("EFETUADA\n");

				}else printf("INVALIDA\n");

			break;

			case 'D':

				scanf("%d %d", &linha, &coluna);

				printf("REMOCAO (%d, %d) ", linha, coluna);

				linha--; coluna--;

				if(validarDupla(linha, coluna)){

					sudokuJogo[linha][coluna] = 0;
					quantRegistros--;

					printf("EFETUADA\n");

				}else printf("INVALIDA\n");

			break;

			case 'V': imprimirSudokuJogo(); break;

			case 'F': printf("FIM DE JOGO\n"); break;

			case 'R':

				jogada = (Jogada*) desempilhar(jogadas);

				if(jogada != NULL){

					sudokuJogo[jogada -> linha][jogada -> coluna] = 0;
					quantRegistros--;

					printf("JOGADA (%d, %d, %d) DESFEITA\n", jogada -> linha + 1, jogada -> coluna + 1, jogada -> valor);

				}else printf("NAO HA JOGADAS PARA RETROCEDER\n");

			break;

			default: printf("OPCAO INVALIDA\n");

		}

	}

	if(quantRegistros == N * N) printf("PARABENS VOCE RESOLVEU O SUDOKU\n");

	imprimirSudokuJogo();

	return 0;

}