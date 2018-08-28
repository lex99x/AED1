// Enunciado
// Zezé viajou para Vitória pela primeirra vez e lá descobriu que as
// passagens de ônibus são calculadas de acordo com a distância até o
// ponto desejado. Ajude Zezé a organizar seus gastos, escrevendo um
// programa que pergunte a distância que ele deseja percorrer em km.
// Calcule o preço da passagem, cobrando R$0,50 por km para viagens
// de até 200km, e R$0,45 para viagens mais longas.
// Exemplo de Entrada
// 201
// Exemplo de Saída
// 90.45

#include <stdio.h>

int main(void){

	double dist = 0.0, preco = 0.0;

	scanf("%lf", &dist);

	if(dist <= 200){

		preco = dist * 0.5;

	}else preco = dist * 0.45;

	printf("%.2lf\n", preco);

	return 0;

}