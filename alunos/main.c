#include <stdio.h>
#include "aluno.h"

int main(void){

    int n;

    printf("\nQuantidade de alunos na turma: ");
    scanf("%d", &n);

    Aluno** alunos = preenche_cadastros(n);

    imprime_aprovados(n, alunos);

    return 0;

}