//Enunciado
//As ações da bolsa de valores podem valorizar ou desvalorizar de acordo
//com o fluxo de compra e venda dos ativos. Essa variação nos preços pode
//ocorrer ao longo do dia no período entre a abertura e fechamento da bolsa.
//As variações de preços são medidas por meio dos percentuais de ganhos ou perdas
//em relação ao preço de abertura da ação.

//Por exemplo, se uma ação iniciou o dia com o valor de R$ 10,00 e obteve
//uma valorização de 10% ao longo do dia. Isso significa que este ativo
//encerrou com o novo valor de R$ 11,00 no fechamento da bolsa.

//Com base nessas informações, escreva um programa que leia:

//O preço da ação na abertura da bolsa.
//O preço da ação no fechamento da bolsa.

//Como saída, imprima o percentual positivo, caso ocorra a valorização da
//ação, ou o percentual negativo, caso ocorra a desvalorização da ação.

//Dicas
//O percentual de ganho ou perda pode ser definido pela análise da diferença
//entre o preço de fechamento e o preço de abertura.
//Os preços devem possuir no máximo duas casas decimais.
//Exemplo de Entrada
//10.0
//8.0
//Exemplo de Saída
//-20.0

#include <stdio.h>

int main(void){

	double abertura = 0.0, fechamento = 0.0, val = 0.0;

	scanf("%lf", &abertura);
	scanf("%lf", &fechamento);

	val = (100 * fechamento/abertura) - 100;

	printf("%.1lf\n", val);

	return 0;

}