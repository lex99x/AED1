// Enunciado
// A(S) NOTA(S) MAIS FREQUENTE(S)
// Em uma série S estão registradas tuplas contendo nota e matrícula
// de cada candidato que fez uma certa prova. Faça um programa que imprima,
// para cada moda (nota com a maior frequência) de S:
// O texto "Nota: " e ao lado o valor da moda;
// Nas linhas seguintes, o texto “Matricula: “ e ao lado a matrícula de
// cada candidato que obteve nota igual a moda. Um registro por linha.
// Considere que a série S está desordenada e tem tamanho de ATÉ 100 elementos,
// e sabe-se que ela termina quando a matrícula for um valor menor que zero,
// considere também que na série S pode haver mais de uma nota com a maior frequência,
// seu programa deve então imprimir cada moda (em ordem crescente) e suas
// respectivas notas logo abaixo (na ordem que aparecem em S).
// Observe o padrão de saída do exemplo abaixo para melhor compreensão.
// Exemplos de Entrada e Saída
// Entrada
// 2176635 67495
// 2174818 41929
// 2173590 54612
// 2173671 60395
// 2175033 12857
// 2175501 21681
// 2171008 12857
// 2174500 59899
// 2173739 48733
// 2173000 41929
// -1
// Saída
// Nota: 128.57
// Matricula: 2175033
// Matricula: 2171008
// Nota: 419.29
// Matricula: 2174818
// Matricula: 2173000

#include <stdio.h>
#define MAX 100

void selsort(int vetor[], int N){

	int i, j;

	for(i = 0; i < N - 1; i++){

		int imenor = i;

		for(j = i + 1; j < N; j++) if(vetor[imenor] > vetor[j]) imenor = j;

		int aux = vetor[i];
		vetor[i] = vetor[imenor];
		vetor[imenor] = aux;

	}

}

int freqNota(int notas[], int quantNotas, int nota){

	int freq = 0, inota;

	for(inota = 0; inota < quantNotas; inota++) if(notas[inota] == nota) freq++;

	return freq;

}

int maiorFreqNotas(int notas[], int quantNotas){

	int freq, mfreq = 0, inota;

	for(inota = 0; inota < quantNotas; inota++){

		freq = freqNota(notas, quantNotas, notas[inota]);

		if(freq > mfreq) mfreq = freq;

	}

	return mfreq;

}

int main(void){

	int matricula, matriculas[MAX], notas[MAX], icandidato;

	scanf("%d", &matricula);

	for(icandidato = 0; matricula >= 0; icandidato++){

		matriculas[icandidato] = matricula;

		scanf("%d", &notas[icandidato]);

		scanf("%d", &matricula);

	}

	int quantCandidatos = icandidato, mfreq = maiorFreqNotas(notas, quantCandidatos);

	int modas[MAX], imoda = 0;

	for(icandidato = 0; icandidato < quantCandidatos; icandidato++){

		int freq = freqNota(notas, quantCandidatos, notas[icandidato]);

		if(freq == mfreq){

			modas[imoda] = notas[icandidato];
			imoda++;

		}

	}

	int quantModas = imoda;

	selsort(modas, imoda);

	int modaAnt = 0;

	for(imoda = 0; imoda < quantModas; imoda++){

		if(modas[imoda] != modaAnt){

			printf("Nota: %.2lf\n", modas[imoda]/100.0);

			modaAnt = modas[imoda];

			for(icandidato = 0; icandidato < quantCandidatos; icandidato++){

				if(notas[icandidato] == modas[imoda]) printf("Matricula: %d\n", matriculas[icandidato]);

			}

		}

	}

	return 0;

}