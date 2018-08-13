// Enunciado
// Desenvolva um programa que leia um número de 4 dígitos e exiba a soma do valor de cada dígito.
// Por exemplo, se o usuário digitar 1212, o programa deve exibir 1 + 2 + 1 + 2 = 6.

// Exemplo de Entrada
// 1212
// Exemplo de Saída
// valor original: 1212
// soma dos digitos: 6

#include <stdio.h>
#include <math.h>

int main(void){

	int num = 0, prim = 0, soma = 0, div = 0, cont = 4, aux = 0;

	scanf("%d", &num);

	aux = num;

	while(cont){

		div = pow(10, cont - 1);
		prim = (int) num/div;
		soma += prim;
		num = num - prim * div;
		cont--;

	}

	printf("valor original: %d\n", aux);
	printf("soma dos digitos: %d\n", soma);

	return 0;

}