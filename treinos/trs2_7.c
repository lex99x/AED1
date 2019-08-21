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
#include <stdlib.h>
#define FATOR_REDUCAO_1 0.3
#define FATOR_REDUCAO_2 0.15

int main(void){

	double n1, n2, n3, n4;
	double p1 = 1.0, p2 = 1.0, p3 = 1.0, p4 = 1.0;

	scanf("%lf %lf", &n1, &n2);

	if((n2 - n1) < -3.0) p2 -= FATOR_REDUCAO_1;
	else if((n2 - n1) > 3.0) p1 -= FATOR_REDUCAO_2;

	scanf("%lf", &n3);

	if((n3 - n2) < -3.0) p3 -= FATOR_REDUCAO_1;
	else if(((n3 - n2) > 3.0) && p2 == 1) p2 -= FATOR_REDUCAO_2;

	scanf("%lf", &n4);

	if((n4 - n3) < -3.0) p4 -= FATOR_REDUCAO_1;
	else if(((n4 - n3) > 3.0) && p3 == 1) p3 -= FATOR_REDUCAO_2;

	double media = (n1 * p1 + n2 * p2 + n3 * p3 + n4 * p4)/(p1 + p2 + p3 + p4);

	printf("%.2lf\n", media);

	return 0;

}