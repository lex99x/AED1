// Enunciado
// Seja S uma sequência de números inteiros onde se registrou, ao longo do dia,
// as mudanças de temperatura em uma adega. Para se estimar a temperatura média
// da sala, além do cálculo convencional de média aritmética, decidiu-se excluir
// da sequência os outliners , isto é, a menor e a maior temperatura evitando assim
// que eles afetem a média. Implemente um programa que resolva este problema,
// considerando que uma temperatura de 500 graus indica o final da sequência, e ela
// não faz parte dos valores observados.
// Dicas
// outliners = os pontos fora da curva.
// valores iguais aos outliners devem ser desconsiderados da sequência no cálculo da média.
// use apenas UMA casa decimal para gerar a saída
// use o tipo double para expressar a média das temperaturas.
// Exemplo de Entrada
// 2 10 5 7 3 -1 10 500
// Exemplo de Saída
// 4.2

#include <stdio.h>

int main(void){

	double media = 0.0;
	int temp, maior, freqMaior, menor, freqMenor, soma = 0, freq = 0, prim = 1;

	scanf("%d", &temp);

	while(temp != 500){

		if(prim){

			prim = 0;
			freqMaior = freqMenor = 1;
			maior = menor = temp;

		}else if(temp > maior){

			freqMaior = 1;
			maior = temp;

		}else if(temp < menor){

			freqMenor = 1;
			menor = temp;

		}else if(temp == maior){

			freqMaior++;

		}else if(temp == menor){

			freqMenor++;

		}

		freq++; soma = soma + temp;

		scanf("%d", &temp);

		if(temp == 500){

			soma = soma - (maior * freqMaior + menor * freqMenor);
			freq = freq - (freqMaior + freqMenor);
			media = (double) soma/freq;

		}

	}

	printf("%.1lf\n", media);

	return 0;

}