// Enunciado
// Na sequência de Fibonacci, os dois primeiros termos são 0 e 1,
// e o valor de cada termo subsequente corresponde à soma dos dois
// termos anteriores: 0, 1, 1, 2, 3, 5, 8, 13, 21, ... Fornecidos
// três números inteiros maiores que zero, em qualquer ordem,
// deseja-se descobrir se eles são termos consecutivos da sequência
// de Fibonacci (saída 1) ou não (saída 0).
// Dicas
// Um número pertence a sequência de Fibonacci se ao menos uma das
// seguintes expressões são quadrados perfeitos: \{5*n^2 + 4\} ou \{5*n^2 - 4\}
// Outros exemplos para validação:
// 2 4 6 ---> 0
// 13 5 8 ---> 1
// 8 13 22 ---> 0
// 0 1 13 ---> 0
// Exemplo de Entrada
// 1 1 2
// Exemplo de Saída
// 1

#include <stdio.h>
#include <math.h>

short pertence(int x){

	double raiz1 = sqrt(5 * x * x + 4);
	double raiz2 = sqrt(5 * x * x - 4);

	return (raiz1 - (int) raiz1 == 0.0) || (raiz2 - (int) raiz2 == 0.0);

}

short consecutivos(int a, int b, int c){

	return (a + b == c) || (a + c == b) || (b + c == a);

}

int main(void){

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	short bool = (pertence(a) && pertence(b) && pertence(c)) && consecutivos(a, b, c);

	printf("%d\n", bool);

	return 0;

}