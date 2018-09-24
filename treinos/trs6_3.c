#include <stdio.h>
#define N 100

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

void imprimirVetor(int* vet, int n){

	for(int i = 0; i < n; i++) printf("%d ", vet[i]);

	printf("\n");

}

int main(void){

	int matricula, matriculas[N], notas[N], freq, mfreq, moda;
	int cont, i, j;
	short primVez = 1;

	scanf("%d", &matricula);

	for(cont = 0; matricula > 0; cont++){

		matriculas[cont] = matricula;

		scanf("%d", &notas[cont]);

		scanf("%d", &matricula);

	}

	for(i = 0; i < cont; i++){

		freq = 0;

		for(j = 0; j < cont; j++){

			if(notas[j] == notas[i]) freq++;

		}

		if(primVez || freq > mfreq){

			primVez = 0;
			mfreq = freq;
			moda = notas[i];

		}

	}

	printf("Nota: %.2lf\n", moda/100.0);

	//selsort(matriculas, cont);
	//selsort(notas, cont);

	//imprimirVetor(matriculas, cont);
	//imprimirVetor(notas, cont);

	for(i = 0; i < cont; i++){

		if(notas[i] == moda) printf("Matricula: %d\n", matriculas[i]);

	}

	return 0;

}