// Enunciado
// AS MELHORIAS DO “DEMANDE AQUI!” DA PREFEITURA
// Objetivo: Contar e listar a redução de demandas de serviço pela população.
// Uma prefeitura criou um aplicativo chamado “Demande aqui!” como canal oficial
// para receber as demandas de serviço para a cidade. O prefeito quer saber quais
// demandas de serviço reduziram em certa taxa após um ano de funcionamento do aplicativo.
// Para isso, as oscilações nas demandas de cada tipo de serviço, em relação ao ano
// anterior, foram armazenadas em uma Série S, cujo o primeiro valor indica qual é a taxa
// de redução X (em valor absoluto) esperada pela prefeitura. Os demais valores indicam:
// aumento na demanda, se foi positivo.
// redução na demanda, se foi negativo.
// Escreva um programa que leia essa Série S de oscilações de demanda.
// Como saída, determine quais e quantos serviços apresentaram uma redução de demanda,
// igual ou inferior a uma taxa X.
// A série S é encerrada quando um valor igual a -5000 foi lido.
// Dicas
// Utilize uma variável contadora para guardar a quantidade de serviços que apresentou
// uma redução de demanda igual ou inferior a X.
// Considere que os valores inseridos como entrada são sempre válidos, ou seja, são inteiros.
// Exemplo (não exaustivo): para a entrada 10 -10  50 0 -50 -5000, a saída será:
// 1
// 4
// 2
// Isso significa que a taxa de redução X esperada é 10 (primeiro valor da entrada)
// e por isso os seguintes serviços apresentam uma redução menor ou igual a -10%:
// a posição 1 e a posição 4, totalizando 2 serviços.
// Exemplo de Entrada
// 10 50 -10 0 -50 -5000
// Exemplo de Saída
// 2
// 4
// 2

#include <stdio.h>

int main(void){

	int taxa, demanda, acm = 0, cont = 1;

	scanf("%d %d", &taxa, &demanda);

	while(demanda != -5000){

		if(demanda <= taxa * -1){

			printf("%d\n", cont);

			acm++;

		}

		cont++;

		scanf("%d", &demanda);

	}

	printf("%d\n", acm);

	return 0;

}