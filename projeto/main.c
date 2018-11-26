#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

typedef struct{

	short status;
	int FA;

} Caixa;

typedef struct{

	int quantCaixasAtuais;
	int quantCaixasNovos;
	Caixa* caixas;
	int medidaAgilidade;
	int X, Y, Z;

} Expresso;

typedef struct{

	int quantItens;
	int tipo;
	int tempoPag;

} Cliente;

typedef struct{

	Caixa* caixa;
	Cliente* cliente;

} FinalAtendimento;

typedef struct{

	int indiceCaixa;
	int duracao;

} Descanso;

typedef struct{

	Caixa* caixa;

} FinalDescanso;

typedef struct{

	int tempoMedio;
	int tempoMaximo;
	int quantPerdas2;
	int quantPerdas3;

} Desempenho;

Caixa* caixaLivre(Expresso* expresso){

	int quantCaixas = expresso -> quantCaixasAtuais + expresso -> quantCaixasNovos;

	for(int cont = 0; cont < quantCaixas; cont++){

		if(expresso -> caixas[cont].status) return &expresso -> caixas[cont];

	}

}

void imprimirEvento(void* info){

	Evento* evento = (Evento*) info;

	printf("%c %lf ", evento -> tipo, evento -> tempo);

	if(evento -> tipo == 'C'){

		Cliente* cliente = (Cliente*) evento -> info;
		printf("%02d %02d %02d\n", cliente -> quantItens, cliente -> tipo, cliente -> tempoPag);

	}else{

		Descanso* descanso = (Descanso*) evento -> info;
		printf("%02d %02d\n", descanso -> indiceCaixa, descanso -> duracao);

	}

}

Expresso* lerExpresso(void){

	Expresso* expresso = (Expresso*) malloc(sizeof(Expresso));

	scanf("%d", &expresso -> quantCaixasAtuais);

	expresso -> caixas = (Caixa*) malloc(expresso -> quantCaixasAtuais * sizeof(Caixa));

	for(int cont = 0; cont < expresso -> quantCaixasAtuais; cont++){

		expresso -> caixas[cont].status = 1;
		scanf("%d", &expresso -> caixas[cont].FA);

	}

	scanf("%d", &expresso -> quantCaixasNovos);

	int quantCaixas = expresso -> quantCaixasAtuais + expresso -> quantCaixasNovos;

	expresso -> caixas = (Caixa*) realloc(expresso -> caixas, quantCaixas * sizeof(Caixa));

	for(int cont = expresso -> quantCaixasAtuais; cont < quantCaixas; cont++){

		expresso -> caixas[cont].status = 1;
		scanf("%d", &expresso -> caixas[cont].FA);

	}

	scanf("%d %d %d %d", &expresso -> medidaAgilidade, &expresso -> X, &expresso -> Y, &expresso -> Z);

	return expresso;

}

void imprimirExpresso(Expresso* expresso){

	int quantCaixas = expresso -> quantCaixasAtuais + expresso -> quantCaixasNovos;

	printf("%d ", expresso -> quantCaixasAtuais);

	for(int cont = 0; cont < expresso -> quantCaixasAtuais; cont++){

		printf("%d ", expresso -> caixas[cont].FA);

	}

	printf("\n%d ", expresso -> quantCaixasNovos);

	for(int cont = expresso -> quantCaixasAtuais; cont < quantCaixas; cont++){

		printf("%d ", expresso -> caixas[cont].FA);

	}

	printf("\n%d\n%d %d %d\n", expresso -> medidaAgilidade, expresso -> X, expresso -> Y, expresso -> Z);

}

int main(void){

	Expresso* expresso = lerExpresso();

	// imprimirExpresso(expresso);

	Agenda* agenda = criarAgenda();
	Evento* evento = criarEvento();
	Cliente* cliente; Descanso* descanso; Caixa* caixa;

	scanf(" %c", &evento -> tipo);

	while(evento -> tipo != 'F'){

		scanf("%lf", &evento -> tempo);

		if(evento -> tipo == 'C'){

			cliente = (Cliente*) malloc(sizeof(Cliente));
			scanf("%d %d %d", &cliente -> quantItens, &cliente -> tipo, &cliente -> tempoPag);
			evento -> info = cliente;

		}else{

			descanso = (Descanso*) malloc(sizeof(Descanso));
			scanf("%d %d", &descanso -> indiceCaixa, &descanso -> duracao);
			evento -> info = descanso;

		}

		inserirEventoAgenda(agenda, evento);

		while(!agendaVazia(agenda)){

			evento = proximoEventoAgenda(agenda);

			double relogio = evento -> tempo;

			if(evento -> tipo == 'C'){

				cliente = (Cliente*) evento -> info;
				caixa = caixaLivre(expresso);
				caixa -> status = 0;

				evento = criarEvento();

				evento -> tipo = 'E';
				evento -> tempo = relogio + expresso -> medidaAgilidade * caixa -> FA * cliente -> quantItens + cliente -> tempoPag;

				FinalAtendimento* finalAtendimento = (FinalAtendimento*) malloc(sizeof(FinalAtendimento));
				finalAtendimento -> caixa = caixa;
				finalAtendimento -> cliente = cliente;

				evento -> info = finalAtendimento;

				inserirEventoAgenda(agenda, evento);

			}else if(evento -> tipo == 'S'){

				descanso = (Descanso*) evento -> info;
				caixa = &expresso -> caixas[descanso -> indiceCaixa];
				caixa -> status = 0;

				FinalDescanso* finalDescanso = (FinalDescanso*) malloc(sizeof(FinalDescanso));
				finalDescanso -> caixa = caixa;

				evento = criarEvento();

				evento -> tipo = 'R';
				evento -> tempo = relogio + descanso -> duracao * 60000.0;
				evento -> info = finalDescanso;

				inserirEventoAgenda(agenda, evento);

			}

		}

		evento = criarEvento();

		scanf(" %c", &evento -> tipo);

	}

	free(evento);

	// imprimirEventosAgenda(agenda, imprimirEvento);

	// while(!agendaVazia(agenda)) proximoEventoAgenda(agenda);

	// printf("%d\n", tamanhoAgenda(agenda));

	return 0;

}