// Enunciado
// A nota mais Frequente
// Em uma série S estão registradas tuplas contendo nota e matrícula
// de cada candidato que fez uma certa prova. Faça um programa que imprima:
// O texto "Nota:" e ao lado a nota que mais ocorreu na prova.
// Nas linhas seguintes, o texto “Matrícula: “ e ao lado a matrícula de cada candidato
// que obteve a nota mais frequente. Um registro por linha.
// Considere que a sequência S está desordenada e tem tamanho de ATÉ 100 elementos,
// e sabe-se que ela termina quando a matrícula for um valor menor que zero.
// Exemplo de Entrada
// 2176635 67495
// 2173590 54612
// 2171008 12857
// 2173671 60395
// 2174818 41929
// 2175033 14410
// 2175501 21681
// 2174500 59899
// 2173739 48733
// 2173000 41929
// -1
// Exemplo de Saída
// Nota: 419.29
// Matricula: 2174818
// Matricula: 2173000

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{

	int matricula;
	int nota;

} Candidato;

void selsort(int** vet, int n){

	int i, j, imenor;
	int* aux;

	for(i = 0; i < n - 1; i++){

		imenor = i;

		for(j = i + 1; j < n; j++) if(*vet[imenor] > *vet[j]) imenor = j;

		aux = vet[i];
		vet[i] = vet[imenor];
		vet[imenor] = aux;

	}

}

int frequencia(Candidato** candidatos, int n, int nota){

	int freq = 0, cont;

	for(cont = 0; cont < n; cont++) if(candidatos[cont] -> nota == nota) freq++;

	return freq;

}

int main(void){

	int matricula, cont;

	Candidato* candidatos[MAX];

	scanf("%d", &matricula);

	for(cont = 0; matricula >= 0; cont++){

		Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));

		candidato -> matricula = matricula;

		scanf("%d", &candidato -> nota);

		candidatos[cont] = candidato;

		scanf("%d", &matricula);

	}

	int freq, mfreq = 0, i;

	for(i = 0; i < cont; i++){

		freq = frequencia(candidatos, cont, candidatos[i] -> nota);

		if(freq > mfreq) mfreq = freq;

	}

	int j = 0;
	int *modas[MAX];

	for(i = 0; i < cont; i++){

		freq = frequencia(candidatos, cont, candidatos[i] -> nota);

		if(freq == mfreq){

			modas[j] = &candidatos[i] -> nota;
			j++;

		}

	}

	selsort(modas, j);

	int ant, k;
	short primVez = 1;

	for(i = 0; i < j; i++){

		if(primVez || *modas[i] != ant){

			primVez = 0;
			ant = *modas[i];

			printf("Nota: %.2lf\n", *modas[i]/100.0);

			for(k = 0; k < cont; k++){

				if(candidatos[k] -> nota == *modas[i]) printf("Matricula: %d\n", candidatos[k] -> matricula);

			}

		}

	}

	return 0;

}