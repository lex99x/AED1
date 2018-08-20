#include <stdio.h>
#include <math.h>

short fibo(int n){

	double raiz1 = sqrt(5 * n * n + 4), raiz2 = sqrt(5 * n * n - 4);

	return (raiz1 - (int) raiz1 == 0.0) || (raiz2 - (int) raiz2 == 0.0);

}

short consecutivo(int a, int b, int c){

	return (a + b == c || a + c == b || b + c == a);

}

int main(void){

	int n1, n2, n3, bool;

	scanf("%d %d %d", &n1, &n2, &n3);

	bool = (fibo(n1) && fibo(n2) && fibo(n3)) && consecutivo(n1, n2, n3);

	printf("%d\n", bool);

}