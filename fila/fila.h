// TAD: fila

typedef struct fila Fila;

Fila* criarFila(void);
void enfileirar(Fila* fila, void* info);
void* desenfileirar(Fila* fila);
void* primeiro(Fila* fila);
void* ultimo(Fila* fila);
int comprimento(Fila* fila);
short vazia(Fila* fila);