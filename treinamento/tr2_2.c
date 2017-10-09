#include <stdio.h>

int main(){

	int temp, soma = 0, cont = 0, menor, maior, freqMaior, freqMenor;

	while(temp != 500){

		scanf("%d", &temp);

		if(temp != 500){

			if(cont == 0){

				freqMaior = 1; maior = temp;
				freqMenor = 1; menor = temp;

			}else{

				if(temp > maior){

					freqMaior = 1; maior = temp;

				}else if(temp < menor){

					freqMenor = 1; menor = temp;

				}else if(temp == maior){

					freqMaior++;

				}else if(temp == menor){

					freqMenor++;

				}

			}

			soma += temp;
			cont++;

		}

	}

	double media = (double)(soma - (maior * freqMaior + menor * freqMenor))/(double)(cont - (freqMaior + freqMenor));

	printf("%.1lf\n", media);

}