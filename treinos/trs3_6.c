// Enunciado
// Desenhando com estrutura de repetição
// Escreva um programa que receba como entrada um caractere qualquer e use-o
// para desenhar um X como o do exemplo de saída abaixo. Obrigatório: use estrutura
// de repetição (laço/loop) para construir o desenho, uma função que desenha um Z
// usando estrutura de repetição será dada como exemplo.
// Dicas
// A saída esperada deve ter 10 linhas e 20 (10×2) caracteres no total
// Use a máscara "%c" para fazer a leitura e saída do caractere
// Exemplo de Entrada
// *
// Exemplo de Saída
// **        **
//  **      **
//   **    **
//    **  **
//     ****
//     ****
//    **  **
//   **    **
//  **      **
// **        **

#include <stdio.h>
#define N 10

void desenharZ(char simbolo){

	int l, c;

	for(l = 1; l <= N; l++) printf("%c", simbolo); printf("\n");

	for(l = 1; l <= N; l++){

		for(c = 1; c <= N; c++){

			if(c == (N - (l - 1))) printf("%c", simbolo); else printf(" ");

		}

		printf("\n");

	}

	for(l = 1; l <= N; l++) printf("%c", simbolo); printf("\n");

}

void desenharX(char simbolo){

	int l, c;

	for(l = 0; l < N; l++){

		for(c = 0; c < N; c++){

			if((l == c) || (l + c == N - 1)) printf("%c%c", simbolo, simbolo); else printf(" ");

		}

		printf("\n");

	}

}

int main(void){

	char simbolo;

	scanf(" %c", &simbolo);

	// desenharZ(simbolo);
	desenharX(simbolo);

	return 0;

}