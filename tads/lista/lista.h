// TAD: lista de inteiros

typedef struct lista{

    int num;
    struct lista* prox;

} Lista;

// Função que inicializa a lista com valor nulo

Lista* lista_cria(void);

// Função que insere elemento na lista

Lista* lista_insere(Lista** lista, int num);

// Função que libera a memória alocada para os elementos da lista

void lista_libera(Lista* lista);

// Função que imprime os elementos da lista

void lista_imprime(Lista* lista);

// Função que verifica se a lista está vazia

short lista_vazia(Lista* lista);

// Função que dada uma lista e o endereço de um elemento da lista,
// retorna o endereço do elemento anterior

Lista* lista_anterior(Lista* lista, Lista* pont);

// Função que retira elemento da lista dado seu endereço de memória

void lista_retira(Lista** lista, Lista* pont);