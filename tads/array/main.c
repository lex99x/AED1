#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	char nome[50];
	int matricula;
	int idade;
	char sexo;

} Aluno;

int main(void){

	Aluno* aluno;
	Array* alunos = criarArray('\0');
	char nome[51];
	int i, j;

	scanf(" %50[^\n]", nome);

	for(i = 0; strcmp(nome, "...") != 0; i++){

		aluno = (Aluno*) malloc(sizeof(Aluno));

		strcpy(aluno -> nome, nome);
		scanf("%d", &aluno -> matricula);
		scanf("%d", &aluno -> idade);
		scanf(" %c", &aluno -> sexo);

		inserirArray(alunos, aluno);

		scanf(" %50[^\n]", nome);

	}

	for(j = 0; j < i; j++){

		aluno = (Aluno*) acessarArray(alunos, j);

		printf("%s\n", aluno -> nome);
		printf("%d\n", aluno -> matricula);
		printf("%d\n", aluno -> idade);
		printf("%c\n", aluno -> sexo);

	}

	liberarArray(alunos);

	return 0;

}