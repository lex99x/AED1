#include <stdio.h>

int main(void){

	int vet[5], i;

	for(i = 0; i < 5; i++){

		scanf("%d", &vet[i]);

	}

	for(i = 0; i < 5; i++){

		printf("%d ", vet[i]);

	}

	return 0;

}