// Enunciado
// O Hertz (Hz) é uma unidade de frequência que mede a quantidade de amostras coletadas em 1 segundo.
// Diversos sensores utilizam o Hertz como unidade de medida para coleta de dados.
// Por exemplo, câmeras capturam imagens a uma frequência média de 30 Hz
// e os sensores inerciais emitem sinais a uma frequência média de 20 Hz.
// Com base nessas informações, escreva um programa que leia:
// A frequência do sensor em Hz.
// O tempo de coleta de dados em minutos.
// Como saída, imprima a quantidade de amostras coletadas no tempo informado.
// Dicas
// Atenção para a conversão de minutos para segundos (60 s = 1 min).
// Certifique-se qual o tipo numérico (int) das entradas e saídas.
// Exemplo de Entrada
// 50
// 3
// Exemplo de Saída
// 9000

#include <stdio.h>
#define SEGS_PER_MIN 60

int main(void){

	int freq, min;

	scanf("%d %d", &freq, &min);

	printf("%d\n", freq * min * SEGS_PER_MIN);

	return 0;

}