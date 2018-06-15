#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku.h"

void preenche_matriz(int matriz[][TAM]){

	int linha = 0, coluna = 0;

	while(linha < TAM){

		coluna = 0;

		while(coluna < TAM){

			matriz[linha][coluna] = 0;

			coluna++;

		}

		linha++;

	}

}

void imprime_matriz(int matriz[][TAM]){

	int linha = 0, coluna = 0;

	printf("    1 2 3 4 5 6 7 8 9\n\n");

	while(linha < TAM){

		coluna = 0;

		while(coluna < TAM){

			if (coluna == 0) printf("%d   ", linha + 1);

			if(matriz[linha][coluna] == 0){

				printf("* ");

			}else{

				printf("%d ", matriz[linha][coluna]);

			}

			if (coluna == TAM - 1) printf("\n");

			coluna++;

		}

		linha++;

	}

}

int range_rand(int min, int max){

	srand(time(NULL) * rand());

	int r = rand() % (max + 1);

	if(r == max)
		return r;
	else
		return r + min;

}

int quadrante(int linha, int coluna){

	if(0 <= linha && linha <= 2){

		if(0 <= coluna && coluna <= 2)
			return 1;
		else if (3 <= coluna && coluna <= 5)
			return 2;
		else
			return 3;

	}else if(3 <= linha && linha <= 5){

		if(0 <= coluna && coluna <= 2)
			return 4;
		else if (3 <= coluna && coluna <= 5)
			return 5;
		else
			return 6;

	}else{

		if(0 <= coluna && coluna <= 2)
			return 7;
		else if (3 <= coluna && coluna <= 5)
			return 8;
		else
			return 9;

	}

}

short verificar_jogada(int linha, int coluna, int valor, int matriz[][TAM]){

	int cont = 0, cont_linha = 0, cont_coluna = 0;

	if(matriz[linha][coluna] != 0){

		return 0;

	}

	while(cont < TAM){

		if(matriz[linha][cont] == valor || matriz[cont][coluna] == valor){

			return 0;

		}

		cont++;

	}

	//return 1;

	switch(quadrante(linha, coluna)){

		case 1:

			while(cont_linha < 3){

				cont_coluna = 0;

				while(cont_coluna < 3){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 2:

			cont_coluna = 3;

			while(cont_linha < 3){

				cont_coluna = 3;

				while(cont_coluna < 6){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 3:

			cont_coluna = 6;

			while(cont_linha < 3){

				cont_coluna = 6;

				while(cont_coluna < TAM){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 4:

			cont_linha = 3;

			while(cont_linha < 6){

				cont_coluna = 0;

				while(cont_coluna < 3){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 5:

			cont_linha = 3;
			cont_coluna = 3;

			while(cont_linha < 6){

				cont_coluna = 3;

				while(cont_coluna < 6){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 6:

			cont_linha = 3;
			cont_coluna = 6;

			while(cont_linha < 6){

				cont_coluna = 6;

				while(cont_coluna < TAM){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 7:

			cont_linha = 6;

			while(cont_linha < TAM){

				cont_coluna = 0;

				while(cont_coluna < 3){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 8:

			cont_linha = 6;
			cont_coluna = 3;

			while(cont_linha < TAM){

				cont_coluna = 3;

				while(cont_coluna < 6){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

		case 9:

			cont_linha = 6;
			cont_coluna = 6;

			while(cont_linha < TAM){

				cont_coluna = 6;

				while(cont_coluna < TAM){

					if(matriz[cont_linha][cont_coluna] == valor)
						return 0;

					cont_coluna++;

				}

				cont_linha++;

			}

		break;

	}

	return 1;

}

void matriz_rand(int matriz[][TAM]){

	int cont = 0, linha = 0, coluna = 0, valor = 0, verificacao = 0;

	while(cont < NIVEL){

		linha = range_rand(0, TAM - 1);
		coluna = range_rand(0, TAM - 1);
		valor = range_rand(1, TAM - 1);
		verificacao = verificar_jogada(linha, coluna, valor, matriz);

		if(verificacao){

			matriz[linha][coluna] = valor;
			cont++;

		}

	}

}
