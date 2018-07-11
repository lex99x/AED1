#include <stdio.h>

int main(){

	int m;

	scanf("%d", &m);

	switch(m){

		case 1: printf("%d\n", 0); break;

		case 2: printf("%d\n%d\n", 0, 1); break;

		default:

			printf("%d\n%d\n", 0, 1);

			int a = 0, b = 1, c;

			for(int i = 1; i < m - 1; i++){

				c = a + b;

				printf("%d\n", c);

				a = b;
				b = c;

			}

	}

}