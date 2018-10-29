// TAD: lista duplamente encadeada

typedef enum{

	INT,
	CHAR,
	LONG,
	FLOAT,
	DOUBLE,
	STRUCT,
	VOID

} Tipo;

typedef struct elemento Elemento;

struct elemento{

	Tipo tipo;
	void* info;
	Elemento* ant;
	Elemento* prox;

};

typedef struct{

	int quant;
	Tipo tipo;
	Elemento* inicio;
	Elemento* final;

} Lista;

// Função que aloca e retorna nova lista
Lista* criarLista(void);

// Função que aloca e retorna novo elemento de lista
Elemento* criarElemento(void* info, Tipo tipo);

// Função que insere novo elemento no ínicio da lista passada
void inserirInicioLista(Lista* lista, void* info, Tipo tipo);

// Função que insere novo elemento no final da lista passada
void inserirFinalLista(Lista* lista, void* info, Tipo tipo);

typedef void* (*Converter)(void* info);

void inserirOrdenadoLista(Lista* lista, void* info, Tipo tipo, Converter converter);

// Função que remove elemento inicial da lista passada
void* removerInicioLista(Lista* lista);

// Função que remove elemento final da lista passada
void* removerFinalLista(Lista* lista);

typedef void (*Imprimir)(void*, Tipo);

// Função que, dada uma lista e a função de impressão específica, imprime toda a lista
void imprimirLista(Lista* lista, Imprimir imprimir);