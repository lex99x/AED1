// TAD: fila

// Definição de tipo fila
typedef struct fila Fila;

// Função que aloca e retorna nova fila
Fila* criarFila(void);

// Função que insere novo elemento no final da fila
void enfileirar(Fila* fila, void* info);

// Função que remove elemento do início da fila
void* desenfileirar(Fila* fila);

// Função que retorna elemento do início da fila
void* primeiroFila(Fila* fila);

// Função que retorna elemento do final da fila
void* ultimoFila(Fila* fila);

// Função que retorna a quantidade de elementos na fila
int comprimentoFila(Fila* fila);

// Função que responde se a fila está vazia
short filaVazia(Fila* fila);