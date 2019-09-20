#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9
#define QUANT_ELEMENTOS_INICIAIS 27

int sudoku[N][N];

int aleatorioIntervaloFechado(int min, int max){

	srand(clock());

	return rand() % ((max + 1) - min) + min;

}

short verificarPosicao(int linha, int coluna){

	return sudoku[linha][coluna] == 0;

}

short verificarLinha(int linha, int valor){

	int coluna;

	for(coluna = 0; coluna < N; coluna++){

		if(sudoku[linha][coluna] == valor) return 0;

	}

	return 1;

}

short verificarColuna(int coluna, int valor){

	int linha;

	for(linha = 0; linha < N; linha++){

		if(sudoku[linha][coluna] == valor) return 0;

	}

	return 1;

}

short verificarQuadrante(int linha, int coluna, int valor){

	int linhaOrigem = 3 * (linha/3), colunaOrigem = 3 * (coluna/3);
	//int linhaOrigem = linha - (linha % 3), colunaOrigem = coluna - (coluna % 3);

	int i, j;

	for(i = linhaOrigem; i < (linhaOrigem + 3); i++){

		for(j = colunaOrigem; j < (colunaOrigem + 3); j++){

			if(sudoku[i][j] == valor) return 0;

		}

	}

	return 1;

}

short verificarJogada(int linha, int coluna, int valor){

	return verificarPosicao(linha, coluna) && verificarLinha(linha, valor) &&
	verificarColuna(coluna, valor) && verificarQuadrante(linha, coluna, valor);

}

void registrarJogada(int linha, int coluna, int valor){

	sudoku[linha][coluna] = valor;

}

void criarSudokuAleatorio(void){

	int linha, coluna;

	for(linha = 0; linha < N; linha++){

		for(coluna = 0; coluna < N; coluna++){

			sudoku[linha][coluna] = 0;

		}

	}

	int cont = 0;

	while(cont < QUANT_ELEMENTOS_INICIAIS){

		int linha = aleatorioIntervaloFechado(0, N - 1);
		int coluna = aleatorioIntervaloFechado(0, N - 1);
		int valor = aleatorioIntervaloFechado(1, N);

		if(verificarJogada(linha, coluna, valor)){

			registrarJogada(linha, coluna, valor);
			cont++;

		}

	}

}

short acharPosicaoVazia(int* linha, int* coluna){

	for(*linha = 0; *linha < N; (*linha)++){

		for(*coluna = 0; *coluna < N; (*coluna)++){

			if(sudoku[*linha][*coluna] == 0) return 1;

		}

	}

	return 0;

}

short verificarSudoku(void){

	int linha, coluna;

	if(!acharPosicaoVazia(&linha, &coluna)) return 1;

	int valor;

	for(valor = 1; valor <= N; valor++){

		if(verificarJogada(linha, coluna, valor)){

			registrarJogada(linha, coluna, valor);

			if(verificarSudoku()) return 1;

			registrarJogada(linha, coluna, 0);

		}

	}

	return 0;

}

void imprimirSudoku(void){

	int linha, coluna;

	printf("    ");

	for(coluna = 1; coluna <= N; coluna++){

		printf("%d ", coluna);

		if(coluna % 3 == 0) printf("  ");

	}

	printf("\n");

	for(linha = 0; linha < N; linha++){

		if(linha % 3 == 0){

			printf("  ");

			for(coluna = 1; coluna <= 25; coluna++) printf("-");

			printf("\n");

		}

		printf("%d ", linha + 1);

		for(coluna = 0; coluna < N; coluna++){

			if(coluna % 3 == 0) printf("| ");

			if(sudoku[linha][coluna] != 0) printf("%d ", sudoku[linha][coluna]); else printf("* ");

		}

		printf("|\n");

	}

	printf("  "); for(coluna = 1; coluna <= 25; coluna++) printf("-"); printf("\n");

}

int main(void){

	criarSudokuAleatorio();

	while(!verificarSudoku()){

		criarSudokuAleatorio();

	}

	imprimirSudoku();

	//int linha, coluna, valor;

	//scanf("%d %d %d", &linha, &coluna, &valor);

	return 0;

}