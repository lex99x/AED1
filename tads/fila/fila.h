// TAD: fila

// Tipos estruturados

typedef struct lista{

    void* info;
    struct lista* prox;

} Lista;

typedef struct{

    Lista* ini;
    Lista* fim;

} Fila;

// Função que aloca a estrutura na memória e a retorna

Fila* fila_criar(void);

// Função que insere elemento no final da fila

void fila_inserir(Fila* fila, void* info);

// Função que remove o elemento no começo da fila

void fila_remover(Fila* fila);

// Função que retorna o endereço do primeiro elemento da fila

void* fila_inicio(Fila* fila);

// Função que retorna o endereço do último elemento da fila

void* fila_fim(Fila* fila);