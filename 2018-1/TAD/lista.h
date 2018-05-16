// TAD: lista de inteiros

typedef struct{

    int num;
    Lista* prox;

} Lista;

// Função que aloca e retorna módulo de lista

Lista* lista_cria(void);

// Função que insere elemento na lista

void lista_insere(Lista* lista, int num);

// Função que libera a memória alocada para uma lista

void lista_libera(Lista* lista);

// Função que imprime elementos da lista

void lista_imprime(Lista* lista);