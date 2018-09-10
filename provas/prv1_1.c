// Enunciado
// Sua mãe recebeu na última conta de água o consumo médio, em metros cúbicos,
// dos 60 meses anteriores. Curiosa ela procurou todas as últimas 60 contas,
// anotou qual havia sido o consumo de cada mês e pediu para você escrever um
// programa que processasse a série S gerada pelas informações ano/mês de
// referência e consumo, informando, ao final do processamento, quais meses
// apresentaram a maior e a menor variação em relação ao consumo médio.
// Dicas
// A leitura das datas pode ser feita usando o scanf(.) com a seguinte máscara:
// scanf("%d/%d", &ano,&mes).
// Para os casos em que haja valores iguas, menor ou maior e para ambos os casos,
// a resposta deve ser a primeira entrada informada.
// Exemplo de Entrada
// 135
// 2017/03 95
// 2017/02 150
// 2017/01 200
// 2016/12 125
// 2016/11 140
// 2016/10 100
// Exemplo de Saída
// 2017/01 200
// 2016/11 140

#include <stdio.h>

int mod(int n){

	return n < 0 ? n * -1 : n;

}

int main(void){

	int consumoMedio, ano, mes, consumo, var, cont;
	int anoMaior, mesMaior, maiorConsumo, maiorVar;
	int anoMenor, mesMenor, menorConsumo, menorVar;

	scanf("%d", &consumoMedio);
	scanf("%d/%d %d", &ano, &mes, &consumo);

	maiorVar = menorVar = var = mod(consumo - consumoMedio);
	anoMaior = anoMenor = ano;
	mesMaior = mesMenor = mes;
	maiorConsumo = menorConsumo = consumo;

	for(cont = 1; cont < 60; cont++){

		scanf("%d/%d %d", &ano, &mes, &consumo);

		var = mod(consumo - consumoMedio);

		if(var > maiorVar){

			maiorVar = var;
			anoMaior = ano;
			mesMaior = mes;
			maiorConsumo = consumo;

		}else if(var < menorVar){

			menorVar = var;
			anoMenor = ano;
			mesMenor = mes;
			menorConsumo = consumo;

		}

	}

	printf("%4d/%02d %d\n", anoMaior, mesMaior, maiorConsumo);
	printf("%4d/%02d %d\n", anoMenor, mesMenor, menorConsumo);

	return 0;

}