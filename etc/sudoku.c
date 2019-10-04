#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9
#define FACIL 72
#define MEDIO 54
#define DIFICIL 36
#define QUANT_VALORES_INICIAIS 27
#define bool unsigned short int

int sudokuJogo[N][N], sudokuParcial[N][N], sudokuCompleto[N][N];

int aleatorioIntervaloFechado(int min, int max){

	srand(clock());

	return rand() % ((max + 1) - min) + min;

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

	int linhaOrigem = 3 * (linha/3), colunaOrigem = 3 * (coluna/3);

	for(linha = linhaOrigem; linha < (linhaOrigem + 3); linha++){

		for(coluna = colunaOrigem; coluna < (colunaOrigem + 3); coluna++){

			if(sudokuJogo[linha][coluna] == valor) return 0;

		}

	}

	return 1;

}

bool validarDupla(int linha, int coluna){

	return (

		validarCoordenada(linha) &&
		validarCoordenada(coluna) &&
		validarPosicaoParcial(linha, coluna) &&
		!validarPosicaoJogo(linha, coluna)

	);

}

bool validarTriplaCPU(int linha, int coluna, int valor){

	return (

		validarPosicaoJogo(linha, coluna) &&
		validarHorizontal(linha, valor) &&
		validarVertical(coluna, valor) &&
		validarQuadrante(linha, coluna, valor)

	);

}

bool validarTriplaJogador(int linha, int coluna, int valor){

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

bool validarSudokuAleatorio(void){

	int linha = 0, coluna = 0, valor;

	do{

		valor = sudokuJogo[linha][coluna];

		if(valor != 0){

			if(coluna == N - 1){

				coluna = 0;
				linha++;

			}else coluna++;

		}

	}while(valor != 0 && linha < N);

	if(valor != 0) return 1;

	for(valor = 1; valor <= N; valor++){

		if(validarTriplaCPU(linha, coluna, valor)){

			sudokuJogo[linha][coluna] =
			sudokuParcial[linha][coluna] =
			sudokuCompleto[linha][coluna] = valor;

			if(validarSudokuAleatorio()) return 1;

			sudokuJogo[linha][coluna] =
			sudokuParcial[linha][coluna] =
			sudokuCompleto[linha][coluna] = 0;

		}

	}

	return 0;

}

void criarSudokuCompleto(void){

	do{

		int linha, coluna, valor, cont = 1;

		for(linha = 0; linha < N; linha++){

			for(coluna = 0; coluna < N; coluna++){

				sudokuJogo[linha][coluna] =
				sudokuParcial[linha][coluna] =
				sudokuCompleto[linha][coluna] = 0;

			}

		}

		while(cont <= QUANT_VALORES_INICIAIS){

			linha = aleatorioIntervaloFechado(0, N - 1);
			coluna = aleatorioIntervaloFechado(0, N - 1);
			valor = aleatorioIntervaloFechado(1, N);

			if(validarTriplaCPU(linha, coluna, valor)){

				sudokuJogo[linha][coluna] =
				sudokuParcial[linha][coluna] =
				sudokuCompleto[linha][coluna] = valor;

				cont++;

			}

		}

	}while(!validarSudokuAleatorio());

}

void criarSudokuParcial(int dificuldade){

	int quantPosicoes = N * N - dificuldade, cont = 1;

	while(cont <= quantPosicoes){

		int linha = aleatorioIntervaloFechado(0, N - 1);
		int coluna = aleatorioIntervaloFechado(0, N - 1);

		if(!validarPosicaoJogo(linha, coluna)){

			sudokuJogo[linha][coluna] =
			sudokuParcial[linha][coluna] = 0;

			cont++;

		}

	}

}

void imprimirSudokuFormatado(void){

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

			if(sudokuJogo[linha][coluna] != 0) printf("%d ", sudokuJogo[linha][coluna]); else printf("* ");

		}

		printf("|\n");

	}

	printf("  "); for(coluna = 1; coluna <= 25; coluna++) printf("-"); printf("\n");

}

void imprimirSudokuSimples(void){

	int linha, coluna = 1;

	printf("%3d", coluna); for(coluna++; coluna <= N; coluna++) printf(" %d", coluna);

	for(linha = 0; linha < N; linha++){

		printf("\n%d", linha + 1);

		for(coluna = 0; coluna < N; coluna++){

			int valor = sudokuJogo[linha][coluna];

			if(valor != 0) printf(" %d", valor); else printf(" *");

		}

	}

	printf("\n");

}

void gravarSudokuSimples(FILE* saida){

	int linha, coluna = 1;

	fprintf(saida, "%3d", coluna); for(coluna++; coluna <= N; coluna++) fprintf(saida, " %d", coluna);

	for(linha = 0; linha < N; linha++){

		fprintf(saida, "\n%d", linha + 1);

		for(coluna = 0; coluna < N; coluna++){

			int valor = sudokuJogo[linha][coluna];

			if(valor != 0) fprintf(saida, " %d", valor); else fprintf(saida, " *");

		}

	}

	fprintf(saida, "\n");

}

void gravarTriplasParciais(FILE* entrada){

	int linha, coluna;

	for(linha = 0; linha < N; linha++){

		for(coluna = 0; coluna < N; coluna++){

			int valor = sudokuParcial[linha][coluna];

			if(valor != 0) fprintf(entrada, "%d %d %d\n", linha + 1, coluna + 1, valor);

		}

	}

	fprintf(entrada, "0\n");

}

void gravarTriplasJogaveis(void){

	FILE* triplasJogaveis = fopen("triplas_jogaveis.txt", "w");

	int linha, coluna;

	for(linha = 0; linha < N; linha++){

		for(coluna = 0; coluna < N; coluna++){

			if(validarPosicaoParcial(linha, coluna)){

				fprintf(triplasJogaveis, "J %d %d %d\n", linha + 1, coluna + 1, sudokuCompleto[linha][coluna]);

			}

		}

	}

	fclose(triplasJogaveis);

}

int main(void){

	int dificuldade = MEDIO, quantRegistros = dificuldade;

	criarSudokuCompleto();
	criarSudokuParcial(dificuldade);

	FILE* entrada = fopen("entrada.txt", "w");
	FILE* saida = fopen("saida.txt", "w");

	gravarTriplasParciais(entrada);
	gravarTriplasJogaveis();

	imprimirSudokuFormatado();
	gravarSudokuSimples(saida);

	char operador = '\0';

	while(operador != 'F' && quantRegistros < N * N){

		scanf(" %c", &operador); fprintf(entrada, "%c", operador);

		switch(operador){

			int linha, coluna, valor;

			case 'J':

				scanf("%d %d %d", &linha, &coluna, &valor);
				fprintf(entrada, " %d %d %d\n", linha, coluna, valor);

				printf("JOGADA (%d, %d, %d) ", linha, coluna, valor);
				fprintf(saida, "JOGADA (%d, %d, %d) ", linha, coluna, valor);

				linha--; coluna--;

				if(validarTriplaJogador(linha, coluna, valor)){

					sudokuJogo[linha][coluna] = valor;
					quantRegistros++;

					printf("EFETUADA\n");
					fprintf(saida, "EFETUADA\n");

				}else{

					printf("INVALIDA\n");
					fprintf(saida, "INVALIDA\n");

				}

			break;

			case 'D':

				scanf("%d %d", &linha, &coluna);
				fprintf(entrada, " %d %d\n", linha, coluna);

				printf("REMOCAO (%d, %d) ", linha, coluna);
				fprintf(saida, "REMOCAO (%d, %d) ", linha, coluna);

				linha--; coluna--;

				if(validarDupla(linha, coluna)){

					sudokuJogo[linha][coluna] = 0;
					quantRegistros--;

					printf("EFETUADA\n");
					fprintf(saida, "EFETUADA\n");

				}else{

					printf("INVALIDA\n");
					fprintf(saida, "INVALIDA\n");

				}

			break;

			case 'V':

				fprintf(entrada, "\n");
				imprimirSudokuFormatado();
				gravarSudokuSimples(saida);

			break;

			case 'F':

				printf("FIM DE JOGO\n");
				fprintf(saida, "FIM DE JOGO\n");

			break;

			default:

				fprintf(entrada, "\n");
				printf("OPCAO INVALIDA\n");
				fprintf(saida, "OPCAO INVALIDA\n");

			break;

		}

	}

	if(quantRegistros == N * N){

		printf("PARABENS VOCE RESOLVEU O SUDOKU\n");
		fprintf(saida, "PARABENS VOCE RESOLVEU O SUDOKU\n");

	}

	imprimirSudokuFormatado();
	gravarSudokuSimples(saida);
	fprintf(entrada, "\n");

	fclose(entrada);
	fclose(saida);

	return 0;

}