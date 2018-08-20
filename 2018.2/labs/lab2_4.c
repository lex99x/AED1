// Enunciado
// Seu professor considera que avaliações binárias (certo ou errado) têm valor
// como instrumento didático mas produzem algumas distorções na nota final
// dos alunos. Para aumentar a justiça na atribuição de notas ele resolveu que
// o descarte das notas que estão fora da curva é uma maneira de implementar uma
// avaliação mais justa. Seu professor realiza 04 provas parciais ao longo do semestre,
// e considera que uma variação de mais de três pontos nas notas de provas consecutivas
// caracteriza uma anomalia na avaliação. Nesse caso, o seu professor emprega um fator
// redutor sobre as provas consecutivas, n(i) e n(i+1), onde i varia de 1 a 3, de acordo
// com o definido a seguir:
// 1) em caso de redução da nota n(i+1)  aplica-se um fator de redução de 30% no peso da nota n(i+1);
// 2) em caso de aumento da nota n(i+1), aplica-se um fator de redução de 15% no peso da nota n(i),
// mas apenas nos casos em que não se verificou o caso 1.
// Implemente o algoritmo que ajude o seu professor a calcular a nota de seus alunos,
// considerando que de posse das notas e dos pesos uma média aritmética ponderada é
// usada para calcular o valor da média parcial. Inicialmente todas as notas têm peso 1.
// Exemplo de Entrada
// 4.0 6.0 7.0 3.5
// Exemplo de Saída
// 5.26

#include <stdio.h>

int main(void){

	double dif = 0.0, somaNota = 0.0, somaPeso = 0.0, media = 0.0, notas[4], pesos[] = {1, 1, 1, 1};
	int i;

	scanf("%lf", &notas[i]);

	for(i = 1; i <= 3; i++){

		scanf("%lf", &notas[i]);

		dif = notas[i] - notas[i - 1];

		if(i == 1){

			if(dif < -3) pesos[i] -= 0.3;

			if(dif > 3) pesos[i - 1] -= 0.15;

		}else{

			if(dif < -3) pesos[i] -= 0.3;

			if(dif > 3 && pesos[i - 1] == 1) pesos[i - 1] -= 0.15;

		}

	}

	for(i = 0; i <= 3; i++){

		somaNota += notas[i] * pesos[i];
		somaPeso += pesos[i];

	}

	media = somaNota/somaPeso;

	printf("%.2lf\n", media);

	return 0;

}