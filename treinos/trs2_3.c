// Enunciado
// O cálculo da idade equivalente humana de um cachorro pode ser melhor
// aproximado considerando seus portes, pois cada raça tem uma equivalência própria.
// Considerando os portes, usa-se a seguinte equivalência:
// raças pequenas: 12,5
// raças médias: 10,5
// raças grandes: 9
// Faça um programa que calcule a idade equivalente humana de seu cachorro,
// considerando a tabela acima.
// Dicas
// Para o tamanho do cachorro, considere as classificações e use os nomes "pequeno",
// "medio" e "grande" para diferenciar as categorias.
// Exemplo de Entrada
// 5
// pequeno
// Exemplo de Saída
// 62.5

#include <stdio.h>
#include <string.h>

int main(void){

	double idadeHumano = 0.0, idadeCachorro = 0.0;
	char porte[8];

	scanf("%lf", &idadeHumano);
	scanf(" %7[^\n]", porte);

	if(!strcmp(porte, "pequeno")) idadeCachorro = idadeHumano * 12.5;

	if(!strcmp(porte, "medio")) idadeCachorro = idadeHumano * 10.5;

	if(!strcmp(porte, "grande")) idadeCachorro = idadeHumano * 9.0;

	printf("%.1lf\n", idadeCachorro);

	return 0;

}