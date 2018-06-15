#include "sudoku.h"

int main(void){

	int matrix[TAM][TAM];

	preenche_matriz(matrix);
	matriz_rand(matrix);
	imprime_matriz(matrix);

	return 0;

}
