#include <stdio.h>
// #include <stdlib.h>

int main(){

    typedef struct{

        int mat;
        char* nome;
        int idade;

    } Aluno;

    Aluno aluno;

    aluno.mat = 21752730;
    aluno.nome = "Alex André Ruiz da Rocha";
    aluno.idade = 17;

    printf("%s, %d, %d\n", aluno.nome, aluno.mat, aluno.idade);

}