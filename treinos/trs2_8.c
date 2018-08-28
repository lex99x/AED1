// Enunciado
// CONVERSOR HERTZ
// Um investidor construiu uma lancha “a jato” a um custo de 1 milhão de reais
// para transportar até 80 passageiros entre Manaus e Nhamundá. Ele deseja saber
// em quanto tempo o seu investimento retornará, e para isso pediu para você
// escrever um programa que responda à questão considerando:
// Uma viagem tem custo fixo de 4,8 mil reais, cobrindo despesas com combustível,
// salário da tripulação, alimentação, e taxas da capitania dos portos;
// As possibilidades de saída das lanchas são:
// 2 viagens por semana
// 4 viagens por semana
// As passagens custam 140 e 100 reais, constituindo-se em dois modelos
// de venda de passagens, chamados de diferenciado e normal;
// Estima-se que viajando duas vezes por semana e usando o modelo normal todas
// as passagens serão vendidas, mas com o modelo diferenciado seriam vendidas
// apenas 90% das poltronas;
// Estima-se que viajando quatro vezes por semana com o modelo normal as vendas
// chegariam a 80% das poltronas, enquanto que o modelo diferenciado
// alcançaria 70% das poltronas.
// Modelo de venda de passagem diferente daqueles mencionados aqui, precisam ser
// ignorados, e a seguinte mensagem enviada: modelo de venda desconhecido
// Como entrada, o programa deve ler:
// O modelo de venda de passagens (Diferenciado ou Normal)
// A quantidade de viagens para o mesmo destino (2 ou 4).
// Como saída, apresentar quantas semanas são necessárias para o seu investimento retornar.
// Conforme a Saída de Exemplo apresentada logo abaixo.
// Dicas
// A quantidade de semanas para o retorno do investimento é calculado como segue:
// Semanas = InvestimentoInicial/(Receita - Despesas)
// Receitas e despesas precisam ser contabilizadas semanalmente.
// Importante, em todos os problemas fique atento ao conteúdo exibido ao término
// do programa, caso ele não siga o padrão de saída apresentado, toda a questão
// será dada como incorreta.
// Exemplo de Entrada
// Diferenciado
// 4
// Exemplo de Saída
// 22 semanas(s)

#include <stdio.h>
#include <string.h>
#define INVESTIMENTO 1000000
#define CAPACIDADE 80
#define CUSTO 4800

short validarModelo(char modelo[13]){

	return !strcmp(modelo, "Normal") || !strcmp(modelo, "Diferenciado");

}

int main(void){

	int quantViagens = 0, preco = 0, despesas = 0, semanas = 0, receita = 0;
	double percentual = 0.0;
	char modelo[13];

	scanf(" %s", modelo);
	scanf("%d", &quantViagens);

	if(validarModelo(modelo)){

		if(!strcmp(modelo, "Normal")){

			preco = 100;

			if(quantViagens == 2) percentual = 1.0;

			if(quantViagens == 4) percentual = 0.8;

		}else{

			preco = 140;

			if(quantViagens == 2) percentual = 0.9;

			if(quantViagens == 4) percentual = 0.7;

		}

		receita = CAPACIDADE * percentual * quantViagens * preco * 2;
		despesas = quantViagens * CUSTO;
		semanas = INVESTIMENTO/(receita - despesas);

		printf("%d semana(s)\n", semanas);

	}else printf("modelo de venda desconhecido\n");

	return 0;

}