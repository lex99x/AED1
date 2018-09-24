// Enunciado
// Junte e mostre em ordem crescente
// Dados dois vetores V1 e V2 ambos com tamanho 10, escreva um programa que após a leitura,
// imprima numa linha os 20 elementos ordenados de forma crescente.
// Dicas
// Lembre-se que a posição de um elemento no vetor é o valor do seu índice MAIS uma unidade,
// por exemplo, o elemento com índice 1 é o segundo elemento no vetor.
// Crie um terceiro vetor cujo tamanho seja a soma do tamanho dos dois vetores a ordenar.
// Exemplo de Entrada
// 10 9 8 7 6 5 4 3 2 1
// 99 100 77 88 55 66 33 44 11 22
// Exemplo de Saída
// 1 2 3 4 5 6 7 8 9 10 11 22 33 44 55 66 77 88 99 100

#include <stdio.h>
#define N 20

void selsort(int* vet, int n){

	int i, j, imenor, aux;

	for(i = 0; i < n - 1; i++){

		imenor = i;

		for(j = i + 1; j < n; j++) if(vet[imenor] > vet[j]) imenor = j;

		aux = vet[i];
		vet[i] = vet[imenor];
		vet[imenor] = aux;

	}

}

int main(void){

	int vet[N], i;

	for(i = 0; i < N; i++) scanf("%d", &vet[i]);

	selsort(vet, N);

	for(i = 0; i < N; i++) printf("%d ", vet[i]);

	return 0;

}