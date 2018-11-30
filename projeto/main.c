#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
#include "../fila/fila.h"

typedef struct{

	int quantCaixasAtuais;
	int quantCaixasNovos;
	int agilidade;
	int X, Y, Z;

} Config;

typedef struct{

	short status;
	int FA;

} Caixa;

typedef struct{

	double relogio;
	Caixa* caixas;
	Fila* fila;
	Config* config;

} Expresso;

typedef struct{

	int quantItens;
	int tipo;
	int tempoPag;

} Cliente;

typedef struct{

	Caixa* caixa;
	Cliente* cliente;

} InicioAtendimento;

typedef struct{

	Caixa* caixa;
	Cliente* cliente;

} FimAtendimento;

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

// Caixa* caixaLivre(Expresso* expresso){

// 	int quantCaixas = expresso -> quantCaixasAtuais + expresso -> quantCaixasNovos;

// 	for(int cont = 0; cont < quantCaixas; cont++){

// 		if(expresso -> caixas[cont].status) return &expresso -> caixas[cont];

// 	}

// 	return NULL;

// }

// void imprimirEvento(void* info){

// 	Evento* evento = (Evento*) info;

// 	printf("%c %lf ", evento -> tipo, evento -> tempo);

// 	if(evento -> tipo == 'C'){

// 		Cliente* cliente = (Cliente*) evento -> info;
// 		printf("%02d %02d %02d\n", cliente -> quantItens, cliente -> tipo, cliente -> tempoPag);

// 	}else{

// 		Descanso* descanso = (Descanso*) evento -> info;
// 		printf("%02d %02d\n", descanso -> indiceCaixa, descanso -> duracao);

// 	}

// }

// void imprimirExpresso(Expresso* expresso){

// 	int quantCaixas = expresso -> quantCaixasAtuais + expresso -> quantCaixasNovos;

// 	printf("%d ", expresso -> quantCaixasAtuais);

// 	for(int cont = 0; cont < expresso -> quantCaixasAtuais; cont++){

// 		printf("%d ", expresso -> caixas[cont].FA);

// 	}

// 	printf("\n%d ", expresso -> quantCaixasNovos);

// 	for(int cont = expresso -> quantCaixasAtuais; cont < quantCaixas; cont++){

// 		printf("%d ", expresso -> caixas[cont].FA);

// 	}

// 	printf("\n%d\n%d %d %d\n", expresso -> agilidade, expresso -> X, expresso -> Y, expresso -> Z);

// }

void agendarFinalAtendimento(Agenda* agenda, int relogio, int agilidade, Caixa* caixa, Cliente* cliente){

	Evento* evento = (Evento*) malloc(sizeof(Evento));

	evento -> tipo = 'E';
	evento -> tempo = relogio + agilidade * caixa -> FA * cliente -> quantItens + cliente -> tempoPag;

	FimAtendimento* fimAtendimento = (FimAtendimento*) malloc(sizeof(FimAtendimento));
	fimAtendimento -> caixa = caixa;
	fimAtendimento -> cliente = cliente;

	evento -> info = fimAtendimento;

	inserirEventoAgenda(agenda, evento);

}

Expresso* lerExpresso(void){

	Expresso* expresso = (Expresso*) malloc(sizeof(Expresso));
	Config* config = (Config*) malloc(sizeof(Config));

	scanf("%d", &config -> quantCaixasAtuais);

	expresso -> caixas = (Caixa*) malloc(config -> quantCaixasAtuais * sizeof(Caixa));

	for(int i = 0; i < config -> quantCaixasAtuais; i++){

		expresso -> caixas[i].status = 1;
		scanf("%d", &expresso -> caixas[i].FA);

	}

	scanf("%d", &config -> quantCaixasNovos);

	int quantCaixas = config -> quantCaixasAtuais + config -> quantCaixasNovos;

	expresso -> caixas = (Caixa*) realloc(expresso -> caixas, quantCaixas * sizeof(Caixa));

	for(int cont = config -> quantCaixasAtuais; cont < quantCaixas; cont++){

		expresso -> caixas[cont].status = 1;
		scanf("%d", &expresso -> caixas[cont].FA);

	}

	scanf("%d %d %d %d", &config -> agilidade, &config -> X, &config -> Y, &config -> Z);

	expresso -> relogio = 0.0;
	expresso -> fila = criarFila();
	expresso -> config = config;

	return expresso;

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

			enfileirar(expresso -> fila, cliente);

		}else{

			descanso = (Descanso*) malloc(sizeof(Descanso));
			scanf("%d %d", &descanso -> indiceCaixa, &descanso -> duracao);
			evento -> info = descanso;

		}

		inserirEventoAgenda(agenda, evento);

		// while(!agendaVazia(agenda)){

		evento = proximoEventoAgenda(agenda);

		double relogio = evento -> tempo;

		if(evento -> tipo == 'C'){

			caixa = caixaLivre(expresso);

			if(caixa != NULL){

				cliente = (Cliente*) desenfileirar(expresso -> fila);

				// int espera = - relogio;

				if(

					(cliente -> tipo == 1) ||
					(cliente -> tipo == 2 && espera <= expresso -> config -> X) ||
					(cliente -> tipo == 3 && espera <= expresso -> config -> Y)

				){

					agendarFinalAtendimento(agenda, expresso -> relogio,
					expresso -> config -> agilidade, caixa, cliente);

				}

			}

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

		}else if(evento -> tipo == 'E'){



		}

		// }

		evento = criarEvento();

		scanf(" %c", &evento -> tipo);

	}

	free(evento);

	// imprimirEventosAgenda(agenda, imprimirEvento);

	// while(!agendaVazia(agenda)) proximoEventoAgenda(agenda);

	// printf("%d\n", tamanhoAgenda(agenda));

	return 0;

}