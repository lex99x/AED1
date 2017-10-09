#include <stdio.h>

int anos(double idade){

    return (int)idade * 10;

}

int meses(double idade){

    return (idade - (int)idade) * 1000; 

}

int main(){

    double idade; 

    scanf("%lf", &idade);

    printf("%d ano(s) %d mes(es)\n", anos(idade), meses(idade));
	
}