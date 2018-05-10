#include <stdio.h>
#include "lista.h"

int main(void){

    List* lst = lst_create();

    int n = 10;
    float k = 3.5;

    lst_insert(&lst, &k);
    lst_insert(&lst, &n);

    printf("%d\n", *((int*) (lst -> data)));

    return 0;

}