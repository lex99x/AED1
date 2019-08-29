// Enunciado
// O consumo de energia dos últimos 6 meses vem registrado na conta que chega
// na casa de cada consumidor da Eletrobrás Amazonas. A sua mãe, preocupada
// com o aumento do consumo e a nova forma de tarifação, deseja saber que mês,
// dos últimos 6, com abril(04) sendo o mês base, apresentou a maior variação
// em relação ao consumo médio registrado no período. Escreva um programa para
// determinar o mês em questão. O consumo médio do período é informado juntamente
// com os consumos mensais.
// Dicas
// O primeiro valor informado é o consumo médio
// A série que segue apresenta duas informações: mês e consumo registrado
// Exemplo de Entrada
// 125
// 04  180
// 03  170
// 02  180
// 01  120
// 12  100
// 11  90
// Exemplo de Saída
// 4

#include <stdio.h>
#include <stdlib.h>

int main(void){

	int consumoMedio, cont, maiorMes = 4, maiorVar = 0;

	scanf("%d", &consumoMedio);

	for(cont = 0; cont < 6; cont++){

		int mes, consumo, var;

		scanf("%d %d", &mes, &consumo);

		var = abs(consumoMedio - consumo);

		if(var > maiorVar){

			maiorMes = mes;
			maiorVar = var;

		}

	}

	printf("%d\n", maiorMes);

	return 0;

}