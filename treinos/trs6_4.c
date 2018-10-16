// Enunciado
// Ordene com menos trocas
// Em uma sequência S de inteiros, estão dispostas as notas dos alunos
// que realizaram a prova do ENEM. Escreva um programa que ordene a
// sequência S e a imprima, considerando:
// Que os dois últimos dígitos da nota são as casas decimais;
// Que o primeiro registro da entrada contém o tamanho da sequência S.
// Existem notas repetidas, por isso sua implementação deve ser estável,
// isto é, a ordem dos valores iguais, no vetor ordenado, é definida pela
// ordem com que eles aparecem na sequência original.
// Use o algoritmo de ordenação, visto em sala de aula, que usa a menor
// quantidade de trocas, no pior cenário. Você deve comprovar o uso do
// algoritmo imprimindo na primeira linha o texto "trocas: " e a seguir
// a quantidade de trocas realizadas.
// Veja no exemplo os modelos de entrada e saída.
// Exemplo de Entrada
// 6
// 79125 96916 83490 21806 6504 96916
// Exemplo de Saída
// trocas: 5
// 65.04 218.06 791.25 834.90 969.16 969.16

#include <stdio.h>

int trocas = 0;

void quicksort(int* vet, int inicio, int fim){

	int pivo, imeio, imin, imax, aux;

	imin = inicio; imax = fim;
	imeio = (imin + imax)/2;
	pivo = vet[imeio];

	do{

		while(vet[imin] < pivo) ++imin;
		while(vet[imax] > pivo) --imax;

		if(imin <= imax){

			aux = vet[imin];
			vet[imin] = vet[imax];
			vet[imax] = aux;

			++imin; --imax;

			trocas++;

		}

	}while(imax > imin);

	if(inicio < imax) quicksort(vet, inicio, imax);

	if(imin < fim) quicksort(vet, imin, fim);

}

int main(void){

	int n;

	scanf("%d", &n);

	int i, notas[n];

	for(i = 0; i < n; i++) scanf("%d", &notas[i]);

	quicksort(notas, 0, n - 1);

	printf("trocas: %d\n", trocas - 1);

	for(i = 0; i < n; i++) printf("%.2lf ", notas[i]/100.0);

	return 0;

}