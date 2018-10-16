// Enunciado
// Consumo do restaurante - maior
// Em uma  sequência S registrou-se a quantidade de consumo de produtos em um restaurante.
// Em uma outra sequência R registrou-se o valor de cada produto. Escreva um programa que
// leia S e R, armazene as suas informações em vetores e indique qual o produto gerou o
// maior lucro para o restaurante. As posições dos produtos nas sequências S e R,
// são os seus identificadores.
// Lembre-se que O número 0 como índice do vetor deve indicar o produto 1,
// assim como, o índice 3 indica o produto 4.
// Mostre ao final da execução do programa o número correspondente ao produto que gerou o
// maior lucro (consumo * valor) no restaurante, por exemplo, se a MAIOR valor total foi
// do produto 0 o resultado deve ser 1, se foi 20 deverá ser 21.
// Dicas
// Lembre-se que o número usado para representar o produto é o índice do vetor
// acrescido de UMA unidade.
// É possível que haja mais de um produto na condição de MAIOR gerador de lucro,
// e portanto todos eles devem ser impressos como saida do programa;
// Exemplos (não exaustivos):
// Consumo por produto S: 10 20 30 40 50 60 70 80 90 100 110 120 -1
// Valor por produto R: 5.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 13.0 14.0 15.0 16.0
// O Valor de resposta deverá ser 12
// Exemplo de Entrada
// 60 20 30 40 50 60 70 80 90 100 110 120 -1
// 32.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 13.0 14.0 15.0 16.0
// Exemplo de Saída
// 1
// 12

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int tam;
	int ocup;
	void** agreg;

} Array;

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam; else array -> tam = 1;

	array -> ocup = 0;
	array -> agreg = malloc(tam * sizeof(void*));

	return array;

}

void inserirArray(Array* array, void* elem){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> agreg = realloc(array -> agreg, array -> tam * sizeof(void*));

	}

	array -> agreg[array -> ocup] = elem;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos < 0 || pos > array -> ocup) exit(0);

	return array -> agreg[pos];

}

int main(void){

	Array* consumos = criarArray('\0');

	int cont;
	int* consumo = (int*) malloc(sizeof(int));

	scanf("%d", consumo);

	while(*consumo >= 0){

		inserirArray(consumos, consumo);

		consumo = (int*) malloc(sizeof(int));

		scanf("%d", consumo);

	}

	free(consumo);

	double lucro, mlucro = 0, precos[consumos -> ocup];

	for(cont = 0; cont < consumos -> ocup; cont++){

		consumo = acessarArray(consumos, cont);

		scanf("%lf", &precos[cont]);

		lucro = *consumo * precos[cont];

		if(lucro > mlucro) mlucro = lucro;

	}

	for(cont = 0; cont < consumos -> ocup; cont++){

		consumo = acessarArray(consumos, cont);

		lucro = *consumo * precos[cont];

		if(lucro == mlucro) printf("%d\n", cont + 1);

	}

	return 0;

}