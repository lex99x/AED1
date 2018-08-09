// Enunciado
// A empresa de ônibus Tucuruí oferece três categorias de assentos:

// Classe A – R$ 80,00

// Classe B – R$ 50,00

// Classe C – R$ 30,00

// Neste contexto, escreva um programa que leia a quantidade de bilhetes vendidos de cada classe.

// Como saída, determine a renda total gerada pela venda dos bilhetes.

// Dicas
// Utilize constantes para armazenar os valores fixos dos preços dos assentos.
// Os preços devem possuir no máximo duas casas decimais.
// Certifique-se qual o tipo numérico (float ou int) das entradas.
// Exemplo de Entrada
// 27
// 10
// 10
// Exemplo de Saída
// 2960.0

#include <stdio.h>

int main(void){

	int a = 0, b = 0, c = 0;
	float preco = 0.0;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	preco = a * 80 + b * 50 + c * 30;

	printf("%.1f\n", preco);

	return 0;

}