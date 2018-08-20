#include <stdio.h>

double menor(double n1, double n2, double n3, double n4){

	double menor = 0.0;

	if(n1 <= n2 && n1 <= n3 && n1 <= n4) menor = n1;

	if(n2 <= n1 && n2 <= n3 && n2 <= n4) menor = n2;

	if(n3 <= n1 && n3 <= n2 && n3 <= n4) menor = n3;

	if(n4 <= n1 && n4 <= n2 && n4 <= n3) menor = n4;

	return menor;

}

double maior(double n1, double n2, double n3, double n4){

	double maior = 0.0;

	if(n1 >= n2 && n1 >= n3 && n1 >= n4) maior = n1;

	if(n2 >= n1 && n2 >= n3 && n2 >= n4) maior = n2;

	if(n3 >= n1 && n3 >= n2 && n3 >= n4) maior = n3;

	if(n4 >= n1 && n4 >= n2 && n4 >= n3) maior = n4;

	return maior;

}

double media(double n1, double n2, double n3, double n4){

	double menorNota = menor(n1, n2, n3, n4), maiorNota = maior(n1, n2, n3, n4);

	return ((n1 + n2 + n3 + n4) - (menorNota + maiorNota))/2.0;

}

int main(void){

	double n1 = 0.0, n2 = 0.0, n3 = 0.0, n4 = 0.0, notaMedia = 0.0;

	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

	notaMedia = media(n1, n2, n3, n4);

	printf("%.2lf\n", notaMedia);

	return 0;

}