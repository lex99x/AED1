#include <stdio.h>

int maior(int xs[]){

	int n = xs[0];

	for(int i = 1; i < 6; i++){

		if(xs[i] > n){

			n = xs[i];

		}

	}

	return n;

}

int main(){

	int x, y, z;

	scanf("%d %d %d", &x, &y, &z);

	int array[] = {x - y, x - z, y - x, y - z, z - x, z- y};

	printf("%d\n", maior(array));

}