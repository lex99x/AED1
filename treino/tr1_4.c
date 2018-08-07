#include <stdio.h>

int maior(int x, int y){

	if(x > y){

		return x;

	}else{

		return y;

	}

}

int menor(int x, int y){

	if(x < y){

		return x;

	}else{

		return y;

	}

}

int interval(int a, int b, int c, int d){

	int maiorI = maior(a, b), menorI = menor(a, b);
	int maiorII = maior(c, d), menorII = menor(c, d);

	return (maiorI >= menorII && menorI <= maiorII) || (maiorII >= menorI && menorII <= maiorI);

}

int main(){

	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("%d\n", interval(a, b, c, d));

}