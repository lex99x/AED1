#include <stdio.h>

double maior(double xs[]){

	double M = xs[0];

	for(int i = 1; i < 4; i++){

		if(xs[i] > M){

			M = xs[i];

		}

	}

   return M;

}

double menor(double xs[]){

	double m = xs[0];

	for(int i = 1; i < 4; i++){

		if(xs[i] < m){

			m = xs[i];

		}

	}

    return m;

}

double media(double ns[]){

    double M = maior(ns), m = menor(ns);
    double soma;

	for(int i = 0; i < 4; i++){

        soma += ns[i];

	}

    return (soma - (m + M))/2;

}

int main(){

    double n1, n2, n3, n4;

    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

    double ns[] = {n1, n2, n3, n4};

    printf("%.2lf\n", media(ns));

}
