// Enunciado
// Temperatura da Plantação
// Dois sensores foram fixados em um pontos estratégicos de uma plantacão de cupuaçu,
// na regão de Presidente Figuereido, com a intenção de medir as variações de temperatura
// na plantação. As medidas registradas por cada sensor geraram uma série S formada por
// pares (x,y) indicando as temperaturas captadas em uma mesma hora do dia. A sua tarefa
// é elaborar um programa que processe S, e determine, para cada dia, a maior e a menor
// variação de temperatura registrada. Os registros de um dia se encerram quando o par (x,y)
// for igual a (100,100) e S se encerra quando a PRIMEIRA temperatura do dia for igual a (-100,-100).
// Quando não houver variações de temperatura, que diferenciem a menor e a maior, seu programa
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
#include <stdlib.h>

int main(void){

	int temp1, temp2;

	scanf("%d %d", &temp1, &temp2);

	while(temp1 != -100 && temp2 != -100){

		int var = abs(temp2 - temp1), maiorVar = var, menorVar = var;

		while(temp1 != 100 && temp2 != 100){

			var = abs(temp2 - temp1);

			if(var > maiorVar) maiorVar = var;
			else if(var < menorVar) menorVar = var;

			scanf("%d %d", &temp1, &temp2);

		}

		if(maiorVar != menorVar) printf("%d %d\n", maiorVar, menorVar);
		else printf("estufa estabilizada\n");

		scanf("%d %d", &temp1, &temp2);

	}

	return 0;

}