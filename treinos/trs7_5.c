// Enunciado
// Candidatos com Maior Nota.
// Em uma série S estão registradas tuplas contendo matrícula e nota de cada candidato
// que fez uma certa prova. Faça um programa que encontre e imprima:
// O texto "nota:" e ao lado a maior nota na prova.
// Na linha seguinte, o texto “matricula(s): “ e depois a(s) matrícula(s) do(s)
// candidato(s) que obtiveram a maior nota. Um registro por linha.
// A(s) matricula(s) deve(m) ser impressas na ordem em que aparecem em S.
// Considere que a sequência S está desordenada e tem tamanho indefinido,
// mas sabe-se que ela termina quando a matrícula for um valor menor que zero.
// Veja os formatos de entrada e saída esperada na entrada exemplo
// Exemplo de Entrada
// 2176462 2644
// 2176635 67495
// 2173590 54612
// 2171008 12857
// 2173671 60395
// 2174818 41929
// 2175033 14410
// 2175501 21681
// 2174500 59899
// 2173739 67495
// -1
// Exemplo de Saída
// nota: 674.95
// matricula(s):
// 2176635
// 2173739

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int tam;
	int ocup;
	void** agreg;

} Array;

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam; else array -> tam = 1;

	array -> ocup = 0;
	array -> agreg = malloc(tam * sizeof(void*));

	return array;

}

void inserirArray(Array* array, void* elem){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> agreg = realloc(array -> agreg, array -> tam * sizeof(void*));

	}

	array -> agreg[array -> ocup] = elem;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos < 0 || pos > array -> ocup) exit(0);

	return array -> agreg[pos];

}

typedef struct{

	int matricula;
	int nota;

} Candidato;

int main(void){

	Array* candidatos = criarArray('\0');
	Candidato* candidato;

	int matricula, mnota, i, j;
	short primVez = 1;

	scanf("%d", &matricula);

	for(i = 0; matricula >= 0; i++){

		candidato = (Candidato*) malloc(sizeof(Candidato));

		candidato -> matricula = matricula;

		scanf("%d", &candidato -> nota);

		inserirArray(candidatos, candidato);

		if(primVez || candidato -> nota > mnota){

			primVez = 0;
			mnota = candidato -> nota;

		}

		scanf("%d", &matricula);

	}

	printf("nota: %.2lf\n", mnota/100.0);
	printf("matricula(s):\n");

	for(j = 0; j < i; j++){

		candidato = acessarArray(candidatos, j);

		if(candidato -> nota == mnota) printf("%d\n", candidato -> matricula);

	}

	return 0;

}