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

double media(double w, double x, double y, double z, double ns[]){

    double soma = w + x + y + z;
    double soma_M = maior(ns) + menor(ns);
    double m2m = (soma - soma_M)/2;

    return (m2m * 8 + soma_M)/10;

}

int main(){

    double w, x, y, z;

    scanf("%lf %lf %lf %lf", &w, &x, &y, &z);

    double ns[] = {w, x, y, z};

    printf("%.2lf\n", media(w, x, y, z, ns));

}