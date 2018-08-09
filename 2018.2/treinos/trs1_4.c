#include <stdio.h>

// Enunciado
// Para atrair mais clientes, uma loja de roupas oferece um desconto de 5%
// em compras de R$200,00 ou mais. Escreva um programa que lê o preço sem
// desconto de uma compra e imprime o valor a ser pago pelo cliente

// Dicas
// Como o resultado deve ser dado em reais, então deve ter duas casas decimais de precisão.

// Exemplos de entradas e saídas esperadas:

// Entrada = 250 ; Saída = 237.5

// Entrada = 195 ; Saída = 195.0

int main(void){

	float preco = 0.0, desconto = 0.0;

	scanf("%f", &preco);

	if(preco < 200){

		printf("%.1f", preco);

	}else{

		desconto = preco * 0.05;

		printf("%.1f\n", preco - desconto);

	}

	return 0;

}