// Enunciado
// Escreva um programa que leia um vetor de inteiros de 11 posições, 
// e em seguida imprima a mediana desse vetor.
// A mediana de um vetor é o valor que se encontra exatamente no meio do vetor.
// Observações!!
// 1) você não pode alterar o vetor (modificar os valores do vetor, nem mover os elementos de posição);
// 2) você não pode usar vetores auxiliares para essa questão.
// Exemplo de Entrada
// 6 7 10 1 4 5 15 2 3 9 8
// Exemplo de Saída
// 6

#include <stdio.h>
#define N 11

int main(void){

	int i, j, vet[N], contMenores, contMaiores;
	short achou = 0;

	for(i = 0; i < N; i++) scanf("%d", &vet[i]);

	for(i = 0; !achou; i++){

		contMenores = contMaiores = 0;

		for(j = 0; j < N; j++){

			if(vet[j] < vet[i]){

				contMenores++;

			}else if(vet[j] > vet[i]){

				contMaiores++;

			}

		}

		if(contMenores == contMaiores){

			printf("%d\n", vet[i]);
			achou = 1;

		}

	}

	return 0;

}