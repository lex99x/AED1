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

int main(void){

	int matricula, candidatos[100][2], freq, mfreq, moda;
	int cont, i, j;
	short primVez = 1;

	scanf("%d", &matricula);

	for(cont = 0; matricula >= 0; cont++){

		candidatos[cont][1] = matricula;
		scanf("%d", &candidatos[cont][2]);
		scanf("%d", &matricula);

	}

	for(i = 0; i < cont; i++){

		freq = 0;

		for(j = 0; j < cont; j++) if(candidatos[j][2] == candidatos[i][2]) freq++;

		if(primVez || freq > mfreq){

			primVez = 0;
			mfreq = freq;
			moda = candidatos[i][2];

		}

	}

	printf("Nota: %.2lf\n", moda/100.0);

	for(i = 0; i < cont; i++) if(candidatos[i][2] == moda) printf("Matricula: %d\n", candidatos[i][1]);

	return 0;

}