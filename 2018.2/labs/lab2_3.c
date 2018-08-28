// Enunciado
// Seu professor realizar quatro avaliações parciais durante o semestre e
// calcula a média parcial (MP) com segue.
// MP = (M2M + P1 + P2)/10
// onde M2M é a média aritmética das chamadas segundas notas, i.e. a segunda
// maior e a segunda menor nota, e P1 e P2 são as outras notas parciais. P1
// sendo a maior nota e P2 sendo a menor nota. Escreva o programa que ajude
// o seu professor a calcular as notas dos alunos. Use no máximo quatro
// variáveis para implementar o programa. Se professor atribui peso 8 para a M2M.
// Exemplo de Entrada
// 5.0 6.0 8.0 10.0
// Exemplo de Saída
// 7.10

#include <stdio.h>

int main(void){

	double maior, menor, S2M, nota;

	scanf("%lf %lf", &maior, &menor);

	if(menor > maior){

		S2M = maior;
		maior = menor;
		menor = S2M;

	}

	scanf("%lf", &nota);

	if(nota <= menor){

		S2M = menor;
		menor = nota;

	}else if(nota >= maior){

		S2M = maior;
		maior = nota;

	}else{

		S2M = nota;

	}

	scanf("%lf", &nota);

	if(nota <= menor){

		S2M += menor;
		menor = nota;

	}else if(nota >= maior){

		S2M += maior;
		maior = nota;

	}else{

		S2M += nota;

	}

	nota = (4.0 * S2M + maior + menor)/10.0;

	printf("%.2lf\n", nota);

	return 0;

}