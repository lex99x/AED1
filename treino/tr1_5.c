#include <stdio.h>

double preco(int dist){

	if(dist <= 200){

		return 0.5 * dist;

	}else{

		return 0.45 * dist;

	}

}

int main(){

	int dist;

	scanf("%d", &dist);

	printf("%.2lf\n", preco(dist));

}