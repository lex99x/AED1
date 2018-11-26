#include <stdlib.h>
#include "../lista/lista.h"
#include "agenda.h"

struct agenda{

	Lista* lista;

};

Evento* criarEvento(void){

	return (Evento*) malloc(sizeof(Evento));

}

Agenda* criarAgenda(void){

	Agenda* agenda = (Agenda*) malloc(sizeof(Agenda));

	agenda -> lista = criarLista();

	return agenda;

}

short comparadorEventos(void* eventoA, void* eventoB){

	return ((Evento*) eventoA) -> tempo <= ((Evento*) eventoB) -> tempo;

}

void inserirEventoAgenda(Agenda* agenda, Evento* evento){

	inserirOrdenadoLista(agenda -> lista, evento, comparadorEventos);

}

Evento* proximoEventoAgenda(Agenda* agenda){

	return removerInicioLista(agenda -> lista);

}

void imprimirEventosAgenda(Agenda* agenda, ImprimirEvento imprimirEvento){

	percorrerLista(agenda -> lista, imprimirEvento);

}

int tamanhoAgenda(Agenda* agenda){

	return tamanhoLista(agenda -> lista);

}

short agendaVazia(Agenda* agenda){

	return listaVazia(agenda -> lista);

}