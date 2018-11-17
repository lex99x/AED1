#include <stdio.h>
#include "lista.h"

// Comando para testar implementação de lista, execute-o pelo terminal dentro da pasta raiz da lista
// gcc -c *.c && gcc -o ../bin/main *.o && mv *.o ../bin/ && ./../bin/main

short menor(void* a, void* b){

	int x = *((int*) a);
	int y = *((int*) b);

	return x < y;

}

void imprimir(void* info){

	printf("%d ", *((int*) info));

}

int main(void){

	Lista* lista = criarLista();

	int a = 1, b = 0, c = 4, d = 3;

	inserirOrdenadoLista(lista, &a, menor);
	inserirOrdenadoLista(lista, &b, menor);
	inserirOrdenadoLista(lista, &c, menor);
	inserirOrdenadoLista(lista, &d, menor);

	percorrerLista(lista, imprimir); printf("\n");

	return 0;

}