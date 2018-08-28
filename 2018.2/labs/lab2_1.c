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

short pertence(int n){

	double raiz1 = sqrt(5 * n * n + 4), raiz2 = sqrt(5 * n * n - 4);

	return (raiz1 - (int) raiz1 == 0.0) || (raiz2 - (int) raiz2 == 0.0);

}

short consecutivo(int a, int b, int c){

	return (a + b == c || a + c == b || b + c == a);

}

int main(void){

	int n1, n2, n3, bool;

	scanf("%d %d %d", &n1, &n2, &n3);

	bool = (pertence(n1) && pertence(n2) && pertence(n3)) && consecutivo(n1, n2, n3);

	printf("%d\n", bool);

}