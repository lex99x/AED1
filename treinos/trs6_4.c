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