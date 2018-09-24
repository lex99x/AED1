// Enunciado
// Ache o Elemento Central
// Elabore um programa que tendo como entrada um conjunto de inteiros separados
// por espaço e finalizado pelo valor -5000, coloque estes valores em um vetor (máx. 100).
// Como saída o seu programa deverá imprimir o valor mediano, se o vetor tiver um número
// ímpar de registros, ou os dois valores medianos, caso tenha número par de registros.
// O processo acima continuará enquanto novos conjuntos de inteiros são lidos na entrada,
// e terminará  ao receber um conjunto unitário, com apenas o valor -5000.
// Exemplo de Entrada
// 3 7 10 18 25 30 80 -5000
// 3 14 15 92 65 35 -5000
// 2 4 8 16 32 64 128 256 512 1024 -5000
// -5000
// Exemplo de Saída
// 18
// 15 92
// 32 64

#include <stdio.h>
#define MAX 100

int main(void){

	int num, nums[MAX], cont;

	scanf("%d", &num);

	do{

		for(cont = 0; num != -5000; cont++){

			nums[cont] = num;

			scanf("%d", &num);

		}

		if(cont % 2 == 0){

			printf("%d %d\n", nums[cont/2 - 1], nums[cont/2]);

		}else{

			printf("%d\n", nums[(cont - 1)/2]);

		}

		scanf("%d", &num);

	}while(num != -5000);

	return 0;

}