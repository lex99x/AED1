// Enunciado
// Desenvolva um programa que leia um número de 4 dígitos e exiba a soma do valor de cada dígito.
// Por exemplo, se o usuário digitar 1212, o programa deve exibir 1 + 2 + 1 + 2 = 6.
// Exemplo de Entrada
// 1212
// Exemplo de Saída
// valor original: 1212
// soma dos digitos: 6

#include <stdio.h>

int main(void){

	int num, dig, soma, aux;

	scanf("%d", &num);

	aux = num;

	dig = aux / 1000;
	aux = aux % 1000;
	soma = dig;

	dig = aux / 100;
	aux = aux % 100;
	soma = soma + dig;

	dig = aux / 10;
	aux = aux % 10;
	soma = soma + dig + aux;

	printf("valor original: %d\n", num);
	printf("soma dos digitos: %d\n", soma);

	return 0;

}