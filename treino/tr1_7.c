#include <stdio.h>

double media(double n[]){

    double dif, soma = n[3], peso = 1;

    for(int i = 0; i < 3; i++){

        dif = n[i + 1] - n[i];

        if(dif < -3){

            peso += 0.7;

        }else if(dif > 3 && peso - (int)peso != 0.7){

            peso += 0.85;

        }else{

            peso++;

        }

        soma += n[i];

    }

    return soma/peso;

}

int main(){

    double n1, n2, n3, n4;

    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

    double n[] = {n1, n2, n3, n4};

    printf("%.2lf", media(n));

}