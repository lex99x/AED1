#include <stdio.h>

int menor(int x, int y, int z){

	if(x < y && x < z){

		return x;

	}else{

		return menor(z, x, y);

	}

}

int main(){

	int x, y, z;

	scanf("%d %d %d", &x, &y, &z);

	printf("%d\n", menor(x, y, z));

}