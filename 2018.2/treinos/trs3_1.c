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

	int maior, menor, tmp, soma = 0, cont = 0, contMaior = 0, contMenor = 0;

	scanf("%d", &tmp);

	maior = menor = tmp;

	while(tmp != 500){

		if(tmp > maior){

			maior = tmp;
			contMaior = 0;

		}else if(tmp < menor){

			menor = tmp;
			contMenor = 0;

		}

		if(tmp == maior) contMaior++;

		if(tmp == menor) contMenor++;

		soma += tmp;
		cont++;

		scanf("%d", &tmp);

	}

	if(maior != 500){

		soma -= maior * contMaior + menor * contMenor;
		cont -= contMaior + contMenor;

		printf("%.1lf\n", (double) soma/cont);

	}

	return 0;

}