// TAD: array de inteiros

typedef struct{

	int tam, ocup, *agreg;

} Array;

// Função que aloca e retorna novo array
Array* criar(int tam);

// Função que insere novo elemento no array
void inserir(Array* array, int num);

// Função que acessa elemento do array pelo índice passado
int acessar(Array* array, int i);

// Função que imprime elementos do array
void imprimir(Array* array);

// Função que libera a memória alocada para o array
void liberar(Array* array);