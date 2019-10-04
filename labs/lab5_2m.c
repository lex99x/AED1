// Enunciado
// Escreva um algoritmos de ordenação em memória que estabeleça uma ordenação
// completa em um vetor que armazena apenas números inteiros. O tamanho do vetor
// será informado juntamente com os valores a serem armazenados no vetor.
// Seu programa ao final deve imprimir a sequência ordenada de forma decrescente, do maior para o menor.
// Dicas
// Três possíveis algoritmos de ordenação: bolha, seleção, inserção.
// Exemplos de Entrada e Saída
// Entrada
// 10
// 6 9 7 8 6 3 2 1 4 5
// Saída
// 9 8 7 6 6 5 4 3 2 1

#include <stdio.h>

void selsort(int vetor[], int N){

	int i, j, imenor, aux;

	for(i = 0; i < N - 1; i++){

		imenor = i;

		for(j = i + 1; j < N; j++) if(vetor[imenor] > vetor[j]) imenor = j;

		aux = vetor[i];
		vetor[i] = vetor[imenor];
		vetor[imenor] = aux;

	}

}

int main(void){

	int N;

	scanf("%d", &N);

	int vetor[N], cont;

	for(cont = 0; cont < N; cont++) scanf("%d", &vetor[cont]);

	selsort(vetor, N);

	for(cont = N - 1; cont >= 0; cont--) printf("%d ", vetor[cont]);

	return 0;

}