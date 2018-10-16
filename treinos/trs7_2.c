// Enunciado
// Menor público de futebol
// Objetivo: Identificar o mês com menor participação de torcedores em um jogo.
// Um vetor armazena em 12 meses (12 posições) a quantidade de presentes por mês
// em jogos de futebol. O número 0 como índice do vetor indica o mês Janeiro, assim
// como, o índice 3 indica o mês Abril. Mostre ao final da execução do programa apresente
// o nome do mês, por exemplo, se a MENOR frequência foi em Janeiro, então o nome "Janeiro"
// deve ser apresentado.
// Dicas
// Por ocorrer de dois ou mais meses apresentarem a menor participação de torcedores;
// imprimar os nomes, sem acentuação, i.e Marco para Março, dos meses
// imprima na ordem em que eles aparecem no calendário;
// E em linhas distintas
// Exemplos (não exaustivos) para o exemplo abaixo:
// Presentes por mês: 10 20 30 40 50 60 70 80 90 100 110 120
// O Valor de resposta deverá ser: Janeiro
// Exemplo de Entrada
// 10 20 30 40 50 60 70 80 90 100 110 120
// Exemplo de Saída
// Janeiro

#include <stdio.h>
#define N 12

int main(void){

	char meses[][N] = {

		"Janeiro",
		"Fevereiro",
		"Marco",
		"Abril",
		"Maio",
		"Junho",
		"Julho",
		"Agosto",
		"Setembro",
		"Outubro",
		"Novembro",
		"Dezembro"

	};

	int cont, mquant, quants[N];

	scanf("%d", &quants[0]);

	mquant = quants[0];

	for(cont = 1; cont < N; cont++){

		scanf("%d", &quants[cont]);

		if(quants[cont] < mquant) mquant = quants[cont];

	}

	for(cont = 0; cont < N; cont++) if(quants[cont] == mquant) printf("%s\n", meses[cont]);

	return 0;

}