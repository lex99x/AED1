// Enunciado
// Crie um programa que calcule quanto um aluno precisa tirar em sua prova final
// ao digitar as três notas parciais do mesmo. Sabe-se que a média para aprovação é 5.

// A média se calcula assim: MF = (2*(MPP) + PF)/3

// Dicas
// Use duas casas decimais após a vírgula.

// Exemplo de Entrada
// 5.0
// 6.0
// 5.5
// Exemplo de Saída
// 4.00

#include <stdio.h>

int main(void){

	float P1, P2, P3, MPP;

	scanf("%f", &P1);
	scanf("%f", &P2);
	scanf("%f", &P3);

	MPP = (P1 + P2 + P3)/3;

	if(MPP >= 7.5){

		printf("0.00");

	}else printf("%.2f\n", 15 - 2 * MPP);

	return 0;

}