// Enunciado
// Fórmula da Panqueca
// Para evitar desperdício na hora de fazer panquecas, Jebediah Kerman derivou
// a seguinte fórmula para calcular a quantidade de massa (em ml) necessária:
// M = (D * D * T * PI * P)/4;
// onde:
// D (cm) é o diâmetro da frigideira.
// T (cm) é a espessura da panqueca (antes de ser enrolada com o recheio).
// P é a quantidade de panquecas que se quer fazer.
// Faça um programa que tenha como entrada estes valores nesta mesma ordem.
// Como saída, seu programa deve calcular e imprimir, com duas casas decimais,
// a quantidade de massa (M) necessária para fazer as panquecas.
// Dicas
// Use o valor da constante pi fornecida pelo módulo math.
// Um valor aproximado pode levar a uma resposta diferente
// daquela esperada pelo CodeBench.
// Exemplo de Entrada
// 23.0
// 0.08
// 14
// Exemplo de Saída
// 465.33

#include <stdio.h>
#define PI 3.14159265358979323846264338327950288

int main(void){

	double D = 0.0, T = 0.0, M = 0.0;
	int P = 0;

	scanf("%lf", &D);
	scanf("%lf", &T);
	scanf("%d", &P);

	M = (D * D * T * PI * P)/4;

	printf("%.2lf\n", M);

	return 0;

}