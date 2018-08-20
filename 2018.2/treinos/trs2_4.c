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

int menor(int x, int y){

	return (x < y ? x : y);

}

int maior(int x, int y){

	return (x > y ? x : y);

}

int main(void){

	int a = 0, b = 0, c = 0, d = 0, bool = 0;
	int maiorAB = 0, menorAB = 0, maiorCD = 0, menorCD = 0;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	maiorAB = maior(a, b); menorAB = menor(a, b);
	maiorCD = maior(c, d); menorCD = menor(c, d);

	bool = (maiorAB >= menorCD && menorAB <= maiorCD) || (maiorCD >= menorAB && menorCD <= maiorAB);

	printf("%d\n", bool);

	return 0;

}