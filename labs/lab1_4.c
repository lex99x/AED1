// Enunciado
// Distância entre Objetos
// A distância entre as duas árvores pode ser calculada pelo observador usando a lei dos cossenos:
// c = sqrt(a * a + b * b - 2 * a * b * cos(y));
// Faça um programa que tenha como entrada, nessa ordem:
// 1. a distância a entre o observador e a primeira árvore.
// 2. a distância b entre o observador e a segunda árvore.
// 3. o angulo y entre a e b (em graus).
// Como saída, seu programa deverá imprimir, com duas casas decimais, o valor de c,
// correspondente à distância entre as duas árvores.
// Dicas
// Para tirar a raiz quadrada, você pode usar a função sqrt da biblioteca math
// A função cos do também da biblioteca math para calcular o coseno de y,
// lembrando que ela recebe como argumento um valor em radianos.
// Para converter um ângulo y de graus para radianos, use a expressão: (y ∗ π)/180.0
// Exemplo de Entrada
// 12.5
// 17.2
// 64.9
// Exemplo de Saída
// 16.42

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846264338327950288

double dist(double a, double b, double y){

	double rad = (y * PI)/180.0;

	return sqrt(a * a + b * b - 2 * a * b * cos(rad));

}

int main(void){

	double a, b, y;

	scanf("%lf %lf %lf", &a, &b, &y);

	printf("%.2lf\n", dist(a, b, y));

	return 0;

}