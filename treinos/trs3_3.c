// Enunciado
// Temperatura da Plantação
// Dois sensores foram fixados em um pontos estratégicos de uma plantacão de cupuaçu,
// na regão de Presidente Figuereido, com a intenção de medir as variações de temperatura
// na plantação. As medidas registradas por cada sensor geraram uma série S formada por
// pares (x,y) indicando as temperaturas captadas em uma mesma hora do dia. A sua tarefa
// é elaborar um programa que processe S, e determine, para cada dia, a maior e a menor
// variação de temperatura registrada. Os registros de um dia se encerram quando o par (x,y)
// for igual a (100,100) e S se encerra quando a PRIMEIRA temperatura do dia for igual a (-100,-100).
// Quando não houve variações de temperatura, que diferenciem a menor e a maior, seu programa
// deve imprimir a mensagem "estufa estabilizada".
// Exemplo de Entrada
// 3 35 31 38 100 100
// 30 30 30 30 30 30 100 100
// 24 20 26 30 28 32 100 100
// -100 -100
// Exemplo de Saída
// 32 7
// estufa estabilizada
// estufa estabilizada

#include <stdio.h>

int modulo(int num){

	return num < 0 ? num * -1 : num;

}

int main(void){

	int tmp1, tmp2, var, maiorVar, menorVar;

	scanf("%d %d", &tmp1, &tmp2);

	while(tmp1 != -100 && tmp2 != -100){

		maiorVar = menorVar = var = modulo(tmp2 - tmp1);

		while(tmp1 != 100 && tmp2 != 100){

			var = modulo(tmp2 - tmp1);

			if(var > maiorVar) maiorVar = var;
			else if(var < menorVar) menorVar = var;

			scanf("%d %d", &tmp1, &tmp2);

		}

		if(maiorVar != menorVar){

			printf("%d %d\n", maiorVar, menorVar);

		}else printf("estufa estabilizada\n");

		scanf("%d %d", &tmp1, &tmp2);

	}

	return 0;

}