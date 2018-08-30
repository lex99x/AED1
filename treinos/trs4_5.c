// Enunciado
// Na entrada principal de Uma fábrica instalou-se um sensor que consegue
// identificar o momento em que uma pessoa passa pela porta. O sensor detectar
// se a pessoa está entrando ou saindo da fábrica, e a hora em que ocorreu o evento.
// Escreva um programa que conta a quantidade de pessoas que passou pela
// porta da fabrica, no período da manhã.
// Considere que:
// 1) A sequência gerada pelo sensor encerra-se quando um valor negativo for lido na coluna do tempo
// 2) Cada linha da entrada é formada por um tripla {tempo, entrando,saindo}
// 3) O período da manhã se estende das 07:00 as 12:00.
// O tempo é dado em segundo desde o instante inicial do dia que gerou a sequência.
// Dicas
// Responda antes de iniciar a implementação as seguintes questões.
// 1) Qual é a minha entrada?
// 2) Qual processamento devo fazer para cada entrada lida?
// 3) Qual é a minha saída? Quando devo gerar a saída.
// Exemplo de Entrada
// 0 10 1
// 2 2 2
// 10 2 3
// 25200 20 2
// 25201 15 25
// 25202 10 2
// 25205 50 2
// 86400 10 16
// -15
// Exemplo de Saída
// 126

#include <stdio.h>
#define MANHA_MIN 25200
#define MANHA_MAX 43200

int main(void){

	int tempo, entrando, saindo, acm = 0;

	scanf("%d", &tempo);

	while(tempo >= 0){

		scanf("%d %d", &entrando, &saindo);

		if(MANHA_MIN <= tempo && tempo <= MANHA_MAX){

			acm += entrando + saindo;

		}

		scanf("%d", &tempo);

	}

	printf("%d\n", acm);

	return 0;

}