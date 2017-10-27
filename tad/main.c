#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Obs.: generalizar fila pro tipo void*

int main(void){

    Fila* fila = fila_cria();

    enfileirar(fila, 'A', 30);
    enfileirar(fila, 'B', 35);
    enfileirar(fila, 'C', 40);

    desenfileirar(fila);

    printf("%c %d\n", fila -> ini -> action, fila -> ini -> val);
    printf("%c %d\n", fila -> fim -> action, fila -> fim -> val);

    return 0;

}