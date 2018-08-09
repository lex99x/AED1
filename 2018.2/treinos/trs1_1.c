#include <stdio.h>

// Enunciado
// Calcule a idade humana equivalente de um cachorro, sabendo que para cada
// ano de vida humano equivale a aproximadamente 10 anos do cachorro.
// O seu programa deve informar, idade do cachorro na forma ano(s) e mes(es),
// no caso de idades humanas não completas.

// Dicas
// Considere que a entrada humana é informada com um número real,
// onde a arte fracionária representa os meses da idade, variando de 0 a 11.

// Exemplo de Entrada
// 1.00
// Exemplo de Saída
// 10 ano(s) 0 mes(es)

int main(void){

	float idade = 0.0;
	int anos = 0, meses = 0;

	scanf("%f", &idade);

	anos = (int) idade * 10;
	meses = (idade - (int) idade) * 1000;

	printf("%d ano(s) %d mes(es)\n", anos, meses);

	return 0;

}