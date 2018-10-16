// Enunciado
// A nota mais Frequente
// Em uma série S estão registradas tuplas contendo nota e matrícula de cada
// candidato que fez uma certa prova. Faça um programa que imprima:
// O texto "Nota:" e ao lado a nota que mais ocorreu na prova.
// Nas linhas seguintes, o texto “Matrícula: “ e ao lado a matrícula de cada
// candidato que obteve a nota mais frequente. Um registro por linha.
// Considere que a sequência S está desordenada e tem tamanho indefinido,
// mas sabe-se que ela termina quando a matrícula for um valor menor que zero.
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

Array* lerCandidatos(void){

	Array* candidatos = criarArray('\0');

	Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));

	scanf("%d", &candidato -> matricula);

	while(candidato -> matricula >= 0){

		scanf("%d", &candidato -> nota);

		inserirArray(candidatos, candidato);

		candidato = (Candidato*) malloc(sizeof(Candidato));

		scanf("%d", &candidato -> matricula);

	}

	free(candidato);

	return candidatos;

}

int	frequencia(Array* candidatos, int nota){

	int freq = 0, cont;

	for(cont = 0; cont < candidatos -> ocup; cont++){

		Candidato* candidato = acessarArray(candidatos, cont);

		if(candidato -> nota == nota) freq++;

	}

	return freq;
}

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

int main(void){

	int freq, mfreq = 0, i, j;

	Array* candidatos = lerCandidatos();

	for(i = 0; i < candidatos -> ocup; i++){

		Candidato* candidato = acessarArray(candidatos, i);

		freq = frequencia(candidatos, candidato -> nota);

		if(freq > mfreq) mfreq = freq;

	}

	Array* modas = criarArray('\0');

	for(i = 0; i < candidatos -> ocup; i++){

		Candidato* candidato = acessarArray(candidatos, i);

		freq = frequencia(candidatos, candidato -> nota);

		if(freq == mfreq) inserirArray(modas, &candidato -> nota);

	}

	selsort((int**) modas -> agreg, modas -> ocup);

	int ant;
	short primVez = 1;

	for(i = 0; i < modas -> ocup; i++){

		int moda = *((int*) acessarArray(modas, i));

		if(primVez || moda != ant){

			primVez = 0;
			ant = moda;

			printf("Nota: %.2lf\n", moda/100.0);

			for(j = 0; j < candidatos -> ocup; j++){

				Candidato* candidato = acessarArray(candidatos, j);

				if(candidato -> nota == moda) printf("Matricula: %d\n", candidato -> matricula);

			}

		}

	}

	return 0;

}