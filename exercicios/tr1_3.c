#include <stdio.h>
#include <string.h>

double hAge(int dAge, char race[]){

    if(strcmp(race, "pequeno") == 0){

        return dAge * 12.5;

    }else if(strcmp(race, "medio") == 0){

        return dAge * 10.5;

    }else{

        return dAge * 9.0;

    }

}

int main(){

    int dAge;
    char race[8];

    scanf("%d", &dAge);
    scanf("%s", race);

    printf("%.1lf", hAge(dAge, race));

}