#include <stdio.h>
#include "fila.h"

int main(void){

    Fila* fila = fila_criar();

    int a = 2, b = 3;

    fila_inserir(fila, &a);
    fila_inserir(fila, &b);
    fila_remover(fila);

    printf("%d\n", *(int*) fila_fim(fila));

    return 0;

}