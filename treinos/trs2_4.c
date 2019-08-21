// Enunciado
// Dados dois intervalos, representados por 4 números, [a, b] e [c, d],
// escreva um programa que verifique se existe sobreposição
// (pelo menos um ponto em comum) entre os intervalos.
// Note que:
// As extremidades dos intervalos podem não estar em ordem crescente.
// O intervalo [a, b] pode ou não estar antes do intervalo [c, d].
// Exemplo:
// Dada a entrada 7 3 4 8, correspondente aos intervalos [7, 3] e [4, 8], a resposta é 1.
// Já para a entrada 9 6 5 -5, a resposta é 0. Seguido de nova linha.
// Dicas
// Em cada intervalo, verifique qual a maior ou a menor extremidade, conforme o caso.
// Depois compare a maior extremidade de um dos intervalos com a menor do outro.

#include <stdio.h>

int main(void){

	int maiorAB, menorAB, maiorCD, menorCD, aux;

	scanf("%d %d", &maiorAB, &menorAB);

	if(menorAB > maiorAB){

		aux = maiorAB;
		maiorAB = menorAB;
		menorAB = aux;

	}

	scanf("%d %d", &maiorCD, &menorCD);

	if(menorCD > maiorCD){

		aux = maiorCD;
		maiorCD = menorCD;
		menorCD = aux;

	}

	short bool = (maiorAB >= menorCD && menorAB <= maiorCD) || (maiorCD >= menorAB & menorCD <= maiorAB);

	printf("%d\n", bool);

	return 0;

}