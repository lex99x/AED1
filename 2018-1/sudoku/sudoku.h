// Interface do sudoku

#define TAM 9
#define NIVEL 16

// Função que preenche a matriz com zeros

void preenche_matriz(int matriz[][TAM]);

// Função que imprime a matriz

void imprime_matriz(int matriz[][TAM]);

// Função auxiliar que gera um número pseudoaleatório em um intervalo fechado

int range_rand(int min, int max);

// Função que retorna a ordem do quadrante de uma célula do jogo

int quadrante(int linha, int coluna);

// Função que verifica se uma jogada é valida

short verificar_jogada(int linha, int coluna, int valor, int matriz[][TAM]);

// Função que preenche a matriz com valores aleatórios para o início do jogo

void matriz_rand(int matriz[][TAM]);
