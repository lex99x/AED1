// Enunciado
// Os correios definem o preço do transporte das mercadorias com base na
// soma dos valores do peso, distância e o imposto ICMS (imposto sobre
// circulação de mercadorias e prestação de serviços).
// Dessa forma, o preço do serviço de transporte de mercadorias é calculado
// com base nas seguintes informações:
// O valor de 1 Kg é R$ 25,00.
// O valor de 1 Km é R$ 0,10.
// A alíquota do ICMS é 12% do valor total.
// Com base nessas informações, escreva um programa que leia:
// O peso do produto (Kg).
// A distância entre o ponto de origem e destino (Km).
// Como saída, imprima o valor total do serviço de transporte.
// O valor do ICMS é obtido pela seguinte formula:
// ValorDoImposto = preco * (icms/100)
// Dicas
// Utilize constantes para armazenar os valores fixos dos preços.
// Certifique-se qual o tipo numérico (int ou float) das entradas e saídas.
// Os preços devem possuir no máximo duas casas decimais.
// Exemplo de Entrada
// 2
// 750
// Exemplo de Saída
// 140.0

#include <stdio.h>

int main(void){

	double peso = 0.0, dist = 0.0, preco = 0.0;

	scanf("%lf", &peso);
	scanf("%lf", &dist);

	preco = peso * 25 + dist * 0.1;
	preco = preco + (preco * 0.12);

	printf("%.2lf\n", preco);

	return 0;

}