#include <stdio.h>

int segundoMaior(int n1, int n2, int n3){

	if((n3 > n2 && n2 > n1) || (n1 > n2 && n2 > n3)){

		return n2;

	}else if((n3 > n1 && n1 > n2) || (n2 > n1 && n1 > n3)){

		return n1;

	}else{

		return n3;

	}

}

int main(){

	int n1, n2, n3;

	scanf("%d %d %d", &n1, &n2, &n3);

	printf("%d\n", segundoMaior(n1, n2, n3));

}