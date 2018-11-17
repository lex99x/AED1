#include <stdio.h>
#include <stdlib.h>
#include "../tads/lista/lista.h"

typedef struct{

	char tipo;
	int tempo;
	void* info;

} Evento;

typedef struct{

	int quantItens;
	int tipo;
	int tempoPag;

} Cliente;

typedef struct{

	int idPDV;
	int duracao;

} Descanso;

short menor(void* a, void* b){

	Evento* eventoA = (Evento*) a;
	Evento* eventoB = (Evento*) b;

	return eventoA -> tempo < eventoB -> tempo;

}

void imprimirCliente(Cliente* cliente){

	printf("%02d %02d %02d\n", cliente -> quantItens, cliente -> tipo, cliente -> tempoPag);

}

void imprimirDescanso(Descanso* descanso){

	printf("%02d %02d\n", descanso -> idPDV, descanso -> duracao);

}

void imprimirEvento(void* info){

	Evento* evento = (Evento*) info;

	printf("%c %02d ", evento -> tipo, evento -> tempo);

	switch(evento -> tipo){

		case 'C': imprimirCliente((Cliente*) evento -> info); break;
		case 'S': imprimirDescanso((Descanso*) evento -> info); break;

	}

}

int main(void){

	// int quantPDVsAtuais;

	// scanf("%d", &quantPDVsAtuais);

	// int FAsAtuais[quantPDVsAtuais];

	// for(int cont = 0; cont < quantPDVsAtuais; cont++) scanf("%d", &FAsAtuais[cont]);

	// int quantPDVsNovos;

	// scanf("%d", &quantPDVsNovos);

	// int FAsNovos[quantPDVsNovos];

	// for(int cont = 0; cont < quantPDVsNovos; cont++) scanf("%d", &FAsNovos[cont]);

	// int medidaAgilidade;

	// scanf("%d", &medidaAgilidade);

	// Leitura de eventos

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

			scanf("%d %d", &descanso -> idPDV, &descanso -> duracao);

			evento -> info = descanso;

		}

		inserirOrdenadoLista(agenda, evento, menor);

		evento = (Evento*) malloc(sizeof(Evento));

		scanf(" %c", &evento -> tipo);

	}

	free(evento);

	percorrerLista(agenda, imprimirEvento);

	return 0;

}