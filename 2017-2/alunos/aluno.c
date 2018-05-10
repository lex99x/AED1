#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

Aluno* init_aluno(void){

    return (Aluno*) malloc(sizeof(Aluno));

}

Aluno** preenche_cadastros(int n){

    Aluno** alunos = (Aluno**) malloc(sizeof(Aluno*) * n);

    for(int i = 0; i < n; i++){

        alunos[i] = init_aluno();

        printf("\nMatrícula: ");
        scanf("%d", &alunos[i] -> matricula);
        printf("Nome: ");
        scanf(" %80[^\n]", alunos[i] -> nome);
        printf("Turma: ");
        scanf("%d", &alunos[i] -> turma);
        printf("P1: ");
        scanf("%f", &alunos[i] -> p1);
        printf("P2: ");
        scanf("%f", &alunos[i] -> p2);
        printf("P3: ");
        scanf("%f", &alunos[i] -> p3);

    }

    return alunos;

}

float calc_media(Aluno* aluno){

    return (aluno -> p1 + aluno -> p2 + aluno -> p3)/3;

}

void imprime_aprovados(int n, Aluno** alunos){

    Aluno* aluno;
    float media;

    printf("\nAprovados: \n");

    for(int i = 0; i < n; i++){

        aluno = alunos[i];
        media = calc_media(aluno);

        if(media >= 5){

            printf("\nMatrícula: %d\n", aluno -> matricula);
            printf("Nome: %s\n", aluno -> nome);
            printf("Turma: %d\n", aluno -> turma);
            printf("Média: %.2f\n", media);

        }

    }

}