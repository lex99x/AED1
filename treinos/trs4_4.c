// Enunciado
// AS CAMPEÃS DO “DEMANDE AQUI!” DA PREFEITURA
// Uma prefeitura criou um aplicativo chamado “Demande aqui!” como canal oficial
// para receber as demandas de serviço para a cidade. O prefeito quer saber quais
// demandas de serviço aumentaram em certa taxa após um ano de funcionamento do aplicativo.
// Para isso, as oscilações nas demandas de cada tipo de serviço, em relação
// ao ano anterior, foram registradas em uma serie S. Escreva um programa que
// leia S determine quais e quantos serviços apresentaram um aumento de demanda,
// igual ou superior a uma taxa X.
// O primeiro valor da série S é a taxa de aumento X esperada pela prefeitura.
// A série S será encerrada quando um valor -5000 for lido.
// Dicas
// Exemplo (não exaustivo): para a entrada 10 50 -40 0 10 -5000, a saída será:
// 1
// 4
// 2
// Isso significa que a taxa de acréscimo X esperada é 10 (primeiro valor de S)
// e por isso os seguintes serviços apresentam um aumento de demanda igual ou
// superior a 10%: o posição 1 e o de posição 4, totalizando 2 serviços.
// Exemplo de Entrada
// 10  50  -40 0 10 -5000
// Exemplo de Saída
// 1
// 4
// 2

#include <stdio.h>

int main(void){

	int taxa, demanda, acm = 0, cont = 1;

	scanf("%d %d", &taxa, &demanda);

	while(demanda != -5000){

		if(demanda >= taxa){

			printf("%d\n", cont);

			acm++;

		}

		cont++;

		scanf("%d", &demanda);

	}

	printf("%d\n", acm);

	return 0;

}