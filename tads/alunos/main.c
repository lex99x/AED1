#include <stdio.h>
#include "aluno.h"

int main(void){

	int n;

	printf("\nPrograma de cadastro de alunos v0.1\n");
	printf("\nQuantidade de alunos na turma: ");
	scanf("%d", &n);

	Aluno** alunos = preenche_cadastros(n);

	imprime_aprovados(n, alunos);

	return 0;

}