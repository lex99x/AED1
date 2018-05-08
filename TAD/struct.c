#include <stlib.h>

Lista* criar_lista(void){

    return (Lista*) malloc(sizeof(Lista));

}

void remover_lista(Lista* lista){

    for(Lista* l = lista; l != NULL; l = l -> ponteiro_no){

        free(l);

    }

}

void inserir_na_lista(int num, Lista* lista){

    Lista* nova_lista = criar_lista();

    nova_lista -> num = num;
    nova_lista -> ponteiro_no = NULL;

    for(Lista* l = lista; l != NULL; l = l -> ponteiro_no){

        if(l -> ponteiro_no == NULL){

            l -> ponteiro_no = nova_lista;

        }

    }

}