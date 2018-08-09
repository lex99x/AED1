// Enunciado
// A imobiliária Imowell, vendedora de imóveis em Manaus, calcula os valores
// dos imóveis com base na área total do espaço e no valor de mercado agregado
// pela localização geográfica do imóvel. Além disso, área total do imóvel pode
// ser dividida em três áreas: privativa, comum e garagem.

// Com base nessas informações, escreva um programa que leia as seguintes informações:

// Preço da área por m2.
// Área privativa – ap (m2).
// Área comum – ac (m2).
// Área da garagem – ag (m2).

// Como saída, imprima o valor total do imóvel, que é dado pela seguinte fórmula:
// PrecoTotal = (ap + ac + ag) * PrecoDaArea

// Dicas
// O preço da área total do imóvel é calculado pela multiplicação do preço
// do metro quadrado pela área total do imóvel.
// Os preços devem possuir no máximo duas casas decimais.
// Certifique-se qual o tipo numérico (float ou int) das entradas e saídas.
// Exemplo de Entrada
// 480.0
// 80
// 50
// 12
// Exemplo de Saída
// 68160.0

#include <stdio.h>

int main(void){

	float preco = 0.0, ap = 0.0, ac = 0.0, ag = 0.0, total = 0.0;

	scanf("%f", &preco);
	scanf("%f", &ap);
	scanf("%f", &ac);
	scanf("%f", &ag);

	total = (ap + ac + ag) * preco;

	printf("%.1f\n", total);

	return 0;

}