// Enunciado
// Carros em um Estacionamento Trapezoidal
// Um estacionamento possui uma forma que se assemelha à de um trapézio.
// Estima-se que esse estacionamento comporte uma certa quantidade de carros por metro quadrado.
// Escreva um programa que leia, na seguinte ordem:
// A estimativa de carros por metro quadrado do estacionamento.
// O comprimento da base maior do trapézio, em metros.
// O comprimento da base menor do trapézio, em metros.
// O comprimento da altura do trapézio, em metros.
// Como saída, o programa deve fornecer a quantidade de carros que cabem no estacionamento.
// Área de um trapézio regular de base maior B, base menor b e altura h:
// h ∙ (B + b) / 2
// Dicas
// Verifique se as variáveis associadas ao problema são reais ou inteiras.
// O valor de saída deve ser um inteiro.
// A ordem de leitura das variáveis de entrada deve obedecer àquela explicitada no enunciado.
// Verifique se o número de entradas especificadas pelo problema corresponde 
// ao número de comandos input() do seu programa.
// Use a função int() para obter a parte inteira de um número.
// Exemplo de Entrada
// 0.5
// 30.0
// 10.0
// 5.0
// Exemplo de Saída
// 50

#include <stdio.h>

int main(void){

	float estimativa = 0.0, baseMaior = 0.0, baseMenor = 0.0,
	altura = 0.0, area = 0.0;
	int quantCarros = 0;

	scanf("%f", &estimativa);
	scanf("%f", &baseMaior);
	scanf("%f", &baseMenor);
	scanf("%f", &altura);

	area = altura * (baseMaior + baseMenor)/2;
	quantCarros = (int) (area * estimativa);

	printf("%d\n", quantCarros);

	return 0;

}