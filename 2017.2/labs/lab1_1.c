#include <stdio.h>

double celsius(int fh){

	return 5*((double)fh-32)/9;

}

int main(){

	int fh;

	scanf("%d", &fh);

	printf("%.2f\n", celsius(fh));

}