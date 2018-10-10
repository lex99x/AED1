// TAD: array

typedef struct{

	int tam;
	int ocup;
	void** agreg;

} Array;

// Função que aloca e retorna novo array
Array* criarArray(int tam);

// Função que insere endereço de novo elemento no array
void inserirArray(Array* array, void* elem);

// Função que acessa endereço de elemento do array por posição
void* acessarArray(Array* array, int pos);

// Função que libera a memória alocada para o array
void liberarArray(Array* array);