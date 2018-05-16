#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* lst_create(void){

    return NULL;

}

void lst_insert(List** lst, void* data){

    List* lst_new = (List*) malloc(sizeof(void*));

    lst_new -> data = data;
    lst_new -> next = *lst;

    *lst = lst_new;

}

short lst_empty(List* lst){

    return lst == NULL;

}