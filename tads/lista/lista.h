// TAD: Lista Duplamente Encadeada (LDE)

// Definições de tipos auxiliares para a lista
typedef struct elemento Elemento;
typedef struct lista Lista;
typedef void (*Callback)(void*);
typedef short (*Comparador)(void*, void*);

// Função que aloca e retorna nova lista
Lista* criarLista(void);

// Função que insere novo elemento na lista em ordem crescente
void inserirOrdenadoLista(Lista* lista, void* info, Comparador comparador);

// Função que insere novo elemento no ínicio da lista
void inserirInicioLista(Lista* lista, void* info);

// Função que insere novo elemento no final da lista
void inserirFinalLista(Lista* lista, void* info);

// Função que remove primeiro elemento da lista
void* removerInicioLista(Lista* lista);

// Função que remove último elemento da lista
void* removerFinalLista(Lista* lista);

// Função que percorre a lista e aplica a callback para cada elemento
void percorrerLista(Lista* lista, Callback callback);

// Função que retorna a quantidade de elementos (tamanho) da lista
int tamanhoLista(Lista* lista);