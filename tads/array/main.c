#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	while(aluno -> matricula >= 0){

		scanf("%d %c", &aluno -> idade, &aluno -> sexo);

		inserirArray(alunos, aluno);

		aluno = (Aluno*) malloc(sizeof(Aluno));

		scanf("%d", &aluno -> matricula);

	}

	free(aluno);

	return alunos;

}

void imprimirAluno(void* info){

	Aluno* aluno = (Aluno*) info;

	printf("%d %d %c\n", aluno -> matricula, aluno -> idade, aluno -> sexo);

}

int main(void){

	Array* alunos = lerAlunos();

	imprimirArray(alunos, imprimirAluno);

	return 0;

}