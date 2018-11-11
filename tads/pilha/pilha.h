// TAD: pilha

typedef struct pilha Pilha;

Pilha* criarPilha(void);
void empilhar(Pilha* pilha, void* info);
void* desempilhar(Pilha* pilha);
int altura(Pilha* pilha);
void* topo(Pilha* pilha);
short vazia(Pilha* pilha);