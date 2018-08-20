// Enunciado
// ESPAÇO VIP
// Um investidor construiu uma lancha “a jato” a um custo de 1 milhão de reais para
// transportar até 80 passageiros entre Manaus às cidades de Parintins e Coari.
// Ele deseja saber em quanto tempo o seu investimento retornará, e para isso pediu
// para você escrever um programa que responda a questão, considerando:
// A viagem (trechos de ida e volta) tem um custo fixo de 10 reais por Km;
// As passagens custam 100 ou 200 reais, constituindo-se no modelo de venda de
// passagens chamados de Executiva e EspaçoVIP;
// Das 80 poltronas, 16 estão reservadas para vendas a 200 reais e o restante,
// 64, estão reservadas para a venda a 100 reais.
// As estimativas de vendas são estas
// Viajando duas vezes por semana para Parintins:
// 64 poltronas Executiva, 13 poltronas EspaçoVIP.
// Viajando duas vezes por semana para Coari:
// 60 poltronas Executiva, 16 poltronas EspaçoVIP.
// Viajando três vezes por semana para Coari:
// 52 poltronas Executiva, 11 poltronas EspaçoVIP.
// Viajando três vezes por semana para Parintins:
// 42 poltronas Executiva; 12 poltronas EspaçoVIP.
// Destinos diferentes daqueles mencionados, serão ignorados, e a seguinte mensagem
// será enviada: destino desconhecido
// Como entrada, o programa deve ler:
// O destino da viagem (Parintins ou Coari)
// A quantidade de viagens feitas por semana (2 ou 3).
// Como saída, apresentar quantas semanas são necessárias para o seu investimento retornar.
// Conforme a Saída de Exemplo apresentada logo abaixo.
// Dicas
// A quantidade de semanas para o retorno do investimento é calculado como segue:
// Semanas = InvestimentoInicial/(Receita - Despesas)
// Receitas e despesas precisam ser contabilizadas semanalmente.
// Distância entre Manaus:
// Parintins é de 446 Km, Coari é de 451 Km
// Importante, em todos os problemas fique atento ao conteúdo exibido ao término do programa,
// caso ele não siga o padrão de saída apresentado, toda a questão será dada como incorreta.
// Exemplo de Entrada
// Parintins
// 3
// Exemplo de Saída
// 77 semana(s)

#include <stdio.h>
#include <string.h>
#define INVESTIMENTO 1000000
#define CUSTO_KM 10
#define PRECO_EXECUTIVO 100
#define PRECO_VIP 200
#define DIST_PARINTINS 446
#define DIST_COARI 451

short validarDestino(char destino[25]){

	return !strcmp(destino, "Parintins") || !strcmp(destino, "Coari");

}

int main(void){

	int quantViagens = 0, semanas = 0, receita = 0, despesas = 0, dist = 0,
	poltronasExecutivas = 0, poltronasVIP = 0;
	char destino[25];

	scanf(" %s", destino);
	scanf("%d", &quantViagens);

	if(validarDestino(destino)){

		if(!strcmp(destino, "Parintins")){

			dist = DIST_PARINTINS;

			if(quantViagens == 2) poltronasExecutivas = 64; poltronasVIP = 13;

			if(quantViagens == 3) poltronasExecutivas = 42; poltronasVIP = 12;

		}else{

			dist = DIST_COARI;

			if(quantViagens == 2) poltronasExecutivas = 60; poltronasVIP = 16;

			if(quantViagens == 3) poltronasExecutivas = 52; poltronasVIP = 11;

		}

		receita = (poltronasExecutivas * PRECO_EXECUTIVO + poltronasVIP * PRECO_VIP) * quantViagens * 2;
		despesas = dist * quantViagens * CUSTO_KM * 2;
		semanas = INVESTIMENTO/(receita - despesas);

		printf("%d semana(s)\n", semanas);

	}else printf("destino desconhecido\n");

	return 0;

}