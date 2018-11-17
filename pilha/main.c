#include <stdio.h>
#include "pilha.h"

// Comando para testar implementação de pilha, execute-o pelo terminal dentro da pasta raiz da pilha
// gcc -c *.c ../lista/lista.c && gcc -o ../bin/main *.o && mv *.o ../bin/ && ./../bin/main

int main(void){

	Pilha* pilha = criarPilha();

	int a = 1, b = 2, c = 3;

	empilhar(pilha, &a);
	empilhar(pilha, &b);
	empilhar(pilha, &c);

	desempilhar(pilha);
	desempilhar(pilha);
	desempilhar(pilha);

	printf("%d\n", pilhaVazia(pilha));

	return 0;

}