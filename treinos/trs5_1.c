// Enunciado
// Em uma sequência S de números inteiros foi registrado as idades dos
// alunos de uma turma de AED-I. Escreva um programa que determine quem
// são os alunos caçulas da turma e qual é a idade deles. Considere que a
// identidade dos alunos é dada pelo posição deles no vetor.
// Dicas
// Lembre-se que a posição de um elemento no vetor é o valor do seu índice MAIS uma unidade;
// O elemento no índice 1 é o segundo elemento no vetor
// O tamanho da sequência S é dado pelo primeiro valor lido da sequência.
// Exemplo de Entrada
// 4 20 19 28 19
// Exemplo de Saída
// Idade: 19
// Alun*(s): 2 4

#include <stdio.h>

int main(void){

	int tam, idade, menorIdade, cont;

	scanf("%d", &tam);

	int idades[tam];

	scanf("%d", &menorIdade);

	idades[0] = menorIdade;

	for(cont = 1; cont < tam; cont++){

		scanf("%d", &idade);

		idades[cont] = idade;

		if(idade < menorIdade) menorIdade = idade;

	}

	printf("Idade: %d\n", menorIdade);
	printf("Alun*(s): ");

	for(cont = 0; cont < tam; cont++){

		if(idades[cont] == menorIdade) printf("%d ", cont + 1);

	}

	return 0;

}