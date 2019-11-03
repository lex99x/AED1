#include <stdio.h>
#include <stdlib.h>
#include "../pilha/pilha.h"
#define N 9
#define bool unsigned short int

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