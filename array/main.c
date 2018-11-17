#include <stdio.h>
#include "array.h"

// Comando para testar implementação de vetor dinâmico (array),
// execute-o pelo terminal dentro da pasta raiz do array
// gcc -c *.c && gcc -o ../bin/main *.o -lm && mv *.o ../bin/ && ./../bin/main

int main(void){

	Array* array = criarArray('\0');

	int a = 10, b = 77, c = 99;

	inserirArray(array, &a, 0);
	inserirArray(array, &b, 1);
	inserirArray(array, &c, 2);

	printf("%d\n", *((int*) acessarArray(array, 2)));

}