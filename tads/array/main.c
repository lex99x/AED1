#include <stdio.h>
#include <stdlib.h>
#include "array.h"

typedef struct{

	int matricula;
	int idade;
	char sexo;

} Aluno;

Array* lerAlunos(void){

	Array* alunos = criarArray('\0');

	Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

	scanf("%d", &aluno -> matricula);

	for(int i = 0; aluno -> matricula >= 0; i++){

		scanf("%d %c", &aluno -> idade, &aluno -> sexo);

		inserirArray(alunos, aluno, i);

		aluno = (Aluno*) malloc(sizeof(Aluno));

		scanf("%d", &aluno -> matricula);

	}

	free(aluno);

	return alunos;

}

void imprimirAlunos(Array* alunos){	

	for(int i = 0; i < alunos -> ocup; i++){

		Aluno* aluno = (Aluno*) acessarArray(alunos, i);

		printf("%d %d %c\n", aluno -> matricula, aluno -> idade, aluno -> sexo);

	}

}

int main(void){

	Array* alunos = lerAlunos();

	printf("Tamanho: %d\n", alunos -> tam);
	printf("Ocupação: %d\n", alunos -> ocup);
	imprimirAlunos(alunos);

	return 0;

}