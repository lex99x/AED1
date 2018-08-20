// Enunciado
// Plantio de grama
// Objetivo: Determinar o valor do serviço.
// A floricultura Sempre Verde oferece o serviço de plantio de grama.
// O custo do serviço depende da área a ser coberta e é dado pela seguinte fórmula:
// Valor = Área * Custo + Adubo
// O custo e o valor do adubo variam conforme a tabela a seguir:
// Área (m2)		Custo		Fertilizante
// [0, 100]			R$ 2,00		R$ 100,00
// ]100, 2500]		R$ 1,80		R$ 150,00
// ]2500, 10000]	R$ 1,50		R$ 200,00
// ]10000, ∞[		R$ 1,20		R$ 250,00
// Escreva um programa que leia a área a ser coberta (em m2) e determine o valor
// total a ser cobrado pela empresa Sempre Verde.
// Dicas
// Verifique se as variáveis associadas ao problema são reais ou inteiras.
// O valor de saída deve ser arredondado com até duas casas decimais.
// Considere que a entrada do programa sempre será um valor maior ou igual a zero.
// Exemplo de Entrada
// 3000
// Exemplo de Saída
// 4700.0

#include <stdio.h>

int main(void){

	double area = 0.0, custo = 0.0, adubo = 0.0, valor = 0.0;

	scanf("%lf", &area);

	if(area >= 0 && area <= 100){

		custo = 2.00;
		adubo = 100.00;

	}else if(area > 100 && area <= 2500){

		custo = 1.80;
		adubo = 150.00;

	}else if(area > 2500 && area <= 10000){

		custo = 1.50;
		adubo = 200.00;

	}else{

		custo = 1.20;
		adubo = 250.00;

	}

	valor = area * custo + adubo;

	printf("%.1lf\n", valor);

	return 0;

}