#include <stdio.h>

int main(){

	int var = 1, prev, ack = 0, timeout = 0, cont = 0;

	while(var >= 1){

		scanf("%d", &var);

		if(cont > 0){

			if(var == prev/2){

				ack++;

			}

			if(var == 1){

				timeout++;

			}

		}

		prev = var; cont++;

	}

	printf("AckD: %d\nTimeOut: %d\n", ack, timeout);

}