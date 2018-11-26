typedef struct{

	char tipo;
	double tempo;
	void* info;

} Evento;

typedef struct agenda Agenda;
typedef void (*ImprimirEvento)(void*);

Evento* criarEvento(void);
Agenda* criarAgenda(void);
void inserirEventoAgenda(Agenda* agenda, Evento* evento);
Evento* proximoEventoAgenda(Agenda* agenda);
void imprimirEventosAgenda(Agenda* agenda, ImprimirEvento imprimirEvento);
int tamanhoAgenda(Agenda* agenda);
short agendaVazia(Agenda* agenda);