#include <stdio.h>
#include "fila.h"

// Comando para testar implementação de fila, execute-o pelo terminal dentro da pasta raiz da fila
// gcc -c *.c ../lista/lista.c && gcc -o ../bin/main *.o && mv *.o ../bin/ && ./../bin/main

int main(void){

	Fila* fila = criarFila();

	int a = 1, b = 2, c = 3;

	enfileirar(fila, &a);
	enfileirar(fila, &b);
	enfileirar(fila, &c);

	desenfileirar(fila);
	desenfileirar(fila);
	desenfileirar(fila);

	printf("%d\n", filaVazia(fila));

	return 0;

}