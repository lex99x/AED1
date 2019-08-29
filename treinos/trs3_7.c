// Enunciado
// MATEMÁGICA DE ADIVINHAÇÃO
// Dado as seis cartelas abaixo, um mágico mostra cartela por cartela a um
// espectador e para cada cartela mostrada, o mágico pergunta se a idade do
// espectador está na cartela mostrada ou não, depois de mostrar as seis cartelas
// e receber as respostas, o mágico revela a idade do espectador.
// Sabendo que o cálculo do valor a ser adivinhado, nesse caso a idade do espectador,
// é dado pelo somatório do primeiro valor de cada cartela onde o número está presente.
// Exemplo: 14 = 2 + 4 + 8, que correspondem aos primeiros elementos
// das cartelas 2, 3 e 4, respectivamente.
// Escreva um programa que recebe como entrada 6 valores booleanos (verdadeiro/falso)
// de forma que 1 é verdadeiro e 0 é falso, cada entrada representa uma das cartelas,
// seu programa deve então imprimir o valor a ser adivinhado.
// Dicas
// Use a função pow() da biblioteca math.h para calcular potências em C
// Exemplo de Entrada
// 1 0 0 1 1 0
// Exemplo de Saída
// 25

#include <stdio.h>
#include <math.h>

int prim(int tab){

	return pow(2, tab - 1);

}

int main(void){

	int soma = 0, tab;

	for(tab = 1; tab <= 6; tab++){

		short bool;

		scanf("%hd", &bool);

		soma = soma + prim(tab) * bool;

	}

	printf("%d\n", soma);

	return 0;

}