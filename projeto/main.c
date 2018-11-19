#include <stdio.h>
#include <stdlib.h>
#include "../lista/lista.h"

typedef struct{

	short status;
	int FA;

} PDV;

typedef struct{

	int quantPDVsAtuais;
	int quantPDVsNovos;
	PDV* PDVsAtuais;
	PDV* PDVsNovos;
	int medidaAgilidade;

} Expresso;

typedef struct{

	int quantItens;
	int tipo;
	int tempoPag;

} Cliente;

typedef struct{

	int indicePDV;
	int duracao;

} Descanso;

typedef struct{

	char tipo;
	int tempo;
	void* info;

} Evento;

void imprimirCliente(Cliente* cliente){

	printf("%02d %02d %02d\n", cliente -> quantItens, cliente -> tipo, cliente -> tempoPag);

}

void imprimirDescanso(Descanso* descanso){

	printf("%02d %02d\n", descanso -> indicePDV, descanso -> duracao);

}

void imprimirEvento(void* info){

	Evento* evento = (Evento*) info;

	printf("%c %02d ", evento -> tipo, evento -> tempo);

	switch(evento -> tipo){

		case 'C': imprimirCliente((Cliente*) evento -> info); break;
		case 'S': imprimirDescanso((Descanso*) evento -> info); break;

	}

}

Expresso* lerExpresso(void){

	Expresso* expresso = (Expresso*) malloc(sizeof(Expresso));

	scanf("%d", &expresso -> quantPDVsAtuais);

	expresso -> PDVsAtuais = (PDV*) malloc(expresso -> quantPDVsAtuais * sizeof(PDV));

	for(int cont = 0; cont < expresso -> quantPDVsAtuais; cont++){

		expresso -> PDVsAtuais[cont].status = 1;

		scanf("%d", &expresso -> PDVsAtuais[cont].FA);

	}

	scanf("%d", &expresso -> quantPDVsNovos);

	expresso -> PDVsNovos = (PDV*) malloc(expresso -> quantPDVsNovos * sizeof(int));

	for(int cont = 0; cont < expresso -> quantPDVsNovos; cont++){

		expresso -> PDVsNovos[cont].status = 1;

		scanf("%d", &expresso -> PDVsNovos[cont].FA);

	}

	scanf("%d", &expresso -> medidaAgilidade);

	return expresso;

}

void imprimirExpresso(Expresso* expresso){

	printf("%d\n", expresso -> quantPDVsAtuais);

	for(int cont = 0; cont < expresso -> quantPDVsAtuais; cont++) printf("%d ", expresso -> PDVsAtuais[cont].FA); printf("\n");

	printf("%d\n", expresso -> quantPDVsNovos);

	for(int cont = 0; cont < expresso -> quantPDVsNovos; cont++) printf("%d ", expresso -> PDVsNovos[cont].FA); printf("\n");

	printf("%d\n", expresso -> medidaAgilidade);

}

short menor(void* a, void* b){

	Evento* eventoA = (Evento*) a;
	Evento* eventoB = (Evento*) b;

	return eventoA -> tempo < eventoB -> tempo;

}

Lista* lerAgenda(void){

	Lista* agenda = criarLista();

	Evento* evento = (Evento*) malloc(sizeof(Evento));

	scanf(" %c", &evento -> tipo);

	while(evento -> tipo != 'F'){

		scanf("%d", &evento -> tempo);

		if(evento -> tipo == 'C'){

			Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

			scanf("%d %d %d", &cliente -> quantItens, &cliente -> tipo, &cliente -> tempoPag);

			evento -> info = cliente;

		}else{

			Descanso* descanso = (Descanso*) malloc(sizeof(Descanso));

			scanf("%d %d", &descanso -> indicePDV, &descanso -> duracao);

			evento -> info = descanso;

		}

		inserirOrdenadoLista(agenda, evento, menor);

		evento = (Evento*) malloc(sizeof(Evento));

		scanf(" %c", &evento -> tipo);

	}

	free(evento);

	return agenda;

}

void imprimirAgenda(Lista* agenda){

	percorrerLista(agenda, imprimirEvento);

}

short agendaVazia(Lista* agenda){

	return listaVazia(agenda);

}

void* proximoEventoAgenda(Lista* agenda){

	return removerInicioLista(agenda);

}

int main(void){

	// Expresso* expresso = lerExpresso();

	// imprimirExpresso(expresso);

	Lista* agenda = lerAgenda();

	while(!agendaVazia(agenda)) proximoEventoAgenda(agenda);

	printf("%d\n", agendaVazia(agenda));

	// imprimirAgenda(agenda);

	return 0;

}