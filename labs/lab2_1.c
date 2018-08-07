#include <stdio.h>

int fibo(int x, int y, int z){

	return x + y == z || x + z == y || y + z == x;

}

int main(){

	int x, y, z;

	scanf("%d %d %d", &x, &y, &z);

	printf("%d", fibo(x, y, z));

}