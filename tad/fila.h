// TAD: pilha

// Tipos estruturados

typedef struct lista{

    char action;
    int val;
    struct lista* prox;

} Lista;

typedef struct fila{

    Lista* ini;
    Lista* fim;

} Fila;

// Função que aloca a estrutura na memória e a retorna

Fila* fila_cria(void);

// Função que insere elemento no final da fila

void enfileirar(Fila* fila, char action, int val);

// Função que remove elemento no começo da fila

void desenfileirar(Fila* fila);