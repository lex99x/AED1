#include <stdio.h>

int soma(int n){

    if(n >= 1000){

        int head = (int)(n/1000);

        return head + soma(n - head * 1000);

    }else if(n >= 100){

        int head = (int)(n/100);

        return head + soma(n - head * 100);

    }else if(n >= 10){

        int head = (int)(n/10);

        return head + soma(n - head * 10);

    }else{

        return n;

    }

}

int main(){

    int n;

    scanf("%d", &n);

    printf("valor original: %d\nsoma dos digitos: %d", n, soma(n));

}