// Enunciado
// Faça um programa que lê 3 números inteiros e imprima o menor deles.
// Use apenas duas variáveis para resolver o problema.
// Dicas
// Faça as comparações dois a dois números

#include <stdio.h>

int main(void){

	int n1 = 0, n2 = 0, n3 = 0, menor = 0;

	scanf("%d %d %d", &n1, &n2, &n3);

	if(n1 < n2 && n1 < n3) menor = n1;

	if(n2 < n1 && n2 < n3) menor = n2;

	if(n3 < n1 && n3 < n2) menor = n3;

	printf("%d\n", menor);

	return 0;

}