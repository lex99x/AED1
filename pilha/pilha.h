// TAD: pilha

// Definição de tipo pilha
typedef struct pilha Pilha;

// Função que aloca e retorna nova pilha
Pilha* criarPilha(void);

// Função que insere elemento no topo da pilha
void empilhar(Pilha* pilha, void* info);

// Função que remove elemento do topo da pilha
void* desempilhar(Pilha* pilha);

// Função que retorna a quantidade de elementos da pilha
int alturaPilha(Pilha* pilha);

// Função que retorna elemento do topo da pilha
void* topoPilha(Pilha* pilha);

// Função que responde se a pilha está vazia
short pilhaVazia(Pilha* pilha);