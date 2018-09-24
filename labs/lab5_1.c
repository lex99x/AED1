// Enunciado
// ACHE OS ALUNOS MAIS NOVOS
// Em uma sequência S de números inteiros foram registradas as idades dos alunos da turma de AED-I.
// Escreva um programa que imprima como saída:
// A menor idade da turma.
// A identidade do(s) aluno(s) com a menor idade. Notar que pode-se tratar de mais do que um aluno.
// Cada ítem acima deve ser impresso numa nova linha e precedido do mesmo texto do exemplo.
// Considere que a identidade dos alunos é dada pelo posição deles no vetor e que o primeiro
// registro em S é uma exceção pois não contém a idade e sim o tamanho da sequência.
// Dicas
// Lembre-se que a posição de um elemento no vetor é o valor do seu índice MAIS uma unidade,
// por exemplo, o elemento com índice 1 é o segundo elemento no vetor.
// Exemplo de Entrada
// 4 20 19 28 19
// Exemplo de Saída
// Idade: 19
// Alun*(s): 2 4

#include <stdio.h>

int main(void){

	int n;

	scanf("%d", &n);

	int i, midade, idades[n];

	scanf("%d", &midade);

	idades[0] = midade;

	for(i = 1; i < n; i++){

		scanf("%d", &idades[i]);

		if(idades[i] < midade) midade = idades[i];

	}

	printf("Idade: %d\n", midade);
	printf("Alun*(s): ");

	for(i = 0; i < n; i++) if(idades[i] == midade) printf("%d ", i + 1);

	return 0;

}