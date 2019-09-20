// Enunciado
// Crie um programa em C para conversão de temperatura.
// Dado um valor em Celsius, calcule e mostre o valor em Fahrenheit.
// Dicas
// O Valor em Celsius deve ser lido do teclado como um ponto flutuante.
// Note que valor de saída deve ter somente duas casas após o ponto.
// Formula de Conversão:
// F = 1.8 * C + 32
// Exemplo de Entrada
// 10
// Exemplo de Saída
// 50.00

#include <stdio.h>

double fahrenheit(double celsius){

	return celsius * 1.8 + 32.0;

}

int main(void){

	double celsius;

	scanf("%lf", &celsius);

	printf("%.2lf\n", fahrenheit(celsius));

	return 0;

}