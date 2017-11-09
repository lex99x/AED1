// Implementação da lista generalizada

// Tipo estruturado

typedef struct list{

    void* data;
    struct list* next;

} List;

// Função que cria e retorna a lista vazia

List* lst_create(void);

// Função que insere elemento na lista;

void lst_insert(List** lst, void* data);