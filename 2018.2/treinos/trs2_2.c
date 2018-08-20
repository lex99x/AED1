// Enunciado
// Escreva um programa que lê três números e determina o segundo menor número entre eles.
// Seu programa deve então imprimir o valor de tal número.
// Dicas
// Considere os números inteiros, e apresenta apenas o valor esperado.
// Exemplo de Entrada
// 10 15 21
// Exemplo de Saída
// 15

#include <stdio.h>

int main(void){

	int n1 = 0, n2 = 0, n3 = 0, smenor = 0;

	scanf("%d %d %d", &n1, &n2, &n3);

	if((n2 < n1 && n1 < n3) || (n3 < n1 && n1 < n2)) smenor = n1;

	if((n1 < n2 && n2 < n3) || (n3 < n2 && n2 < n1)) smenor = n2;

	if((n1 < n3 && n3 < n2) || (n2 < n3 && n3 < n1)) smenor = n3;

	printf("%d\n", smenor);

	return 0;

}