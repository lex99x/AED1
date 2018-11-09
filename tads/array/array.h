// TAD: array

typedef struct{

	int tam;
	int ocup;
	void** vet;

} Array;

// Função que aloca e retorna novo array
Array* criarArray(int tam);

// Função que insere endereço de novo elemento no array
void inserirArray(Array* array, void* info, int pos);

// Função que acessa endereço de elemento do array por posição
void* acessarArray(Array* array, int pos);