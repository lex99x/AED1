#include "lista.h"

void main(void){

    Lista* lista = lista_cria();

    Lista* pont1 = lista_insere(&lista, 10);
    Lista* pont2 = lista_insere(&lista, 15);
    Lista* pont3 = lista_insere(&lista, 20);

    lista_imprime(lista);

    lista_retira(&lista, pont1);
    lista_retira(&lista, pont2);
    lista_retira(&lista, pont3);

    lista_imprime(lista);

}