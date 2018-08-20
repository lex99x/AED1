// Enunciado
// Um cliente ganhou um cupom com 35% de desconto na compra de uma passagem
// aérea para acompanhante para voos de ida e volta para qualquer destino do Brasil.
// A regra do cupom define que o desconto é válido somente para a compra de
// duas passagens aéreas, sendo que, o desconto é dado somente para a passagem do acompanhante.
// Escreva um programa que leia:
// Preço da passagem do cliente.
// Preço da passagem do acompanhante.
// Como saída, imprima os valores finais de cada uma das passagens e o valor
// total da compra. O valor total do desconto é dado pela seguinte fórmula:
// Desconto = precoAcompanhante - (precoAcompanhante * 0.35)
// Dicas
// Os valores devem possuir no máximo duas casas decimais.
// Utilize uma constante para armazenar o valor do desconto.
// Certifique-se qual o tipo numérico (float ou int) das entradas e saídas.
// Exemplo de Entrada
// 1150.0
// 1200.0
// Exemplo de Saída
// 1150.0
// 780.0
// 1930.0

#include <stdio.h>

int main(void){

	double cliente = 0.0, acomp = 0.0, desconto = 0.0, total = 0.0;

	scanf("%lf", &cliente);
	scanf("%lf", &acomp);

	desconto = acomp - acomp * 0.35;
	total = cliente + desconto;

	printf("%.2lf\n", cliente);
	printf("%.2lf\n", desconto);
	printf("%.2lf\n", total);

	return 0;

}