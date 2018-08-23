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

int main(void){

	int consumoMedio, mes, consumoMes, maiorMes, maiorVar, i;

	scanf("%d", &consumoMedio);
	scanf("%d %d", &mes, &consumoMes);

	maiorVar = consumoMes - consumoMedio;
	maiorMes = mes;

	for(i = 1; i < 6; i++){

		scanf("%d %d", &mes, &consumoMes);

		if(consumoMes - consumoMedio > maiorVar) maiorMes = mes;

	}

	printf("%d\n", maiorMes);

	return 0;

}