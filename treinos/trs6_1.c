// Enunciado
// MEDIANA DOS SALÁRIOS
// A lei da transparência obriga os órgãos e autarquias federais a tornar públicos os seus gastos.
// Em prol desta lei, pretende-se implementar em um tribunal federal um serviço que permita acesso aos
// gastos com pagamentos de salários. Como parte deste serviço, você deverá fazer um programa cuja entrada:
// É uma sequência S, de triplas s que contém: a função, matrícula, e
// salário de cada funcionário, constante na folha salarial do referido tribunal;
// A função é representada por uma letra A - Administrativo ou
// N - Não Administrativo, para preservação das identidades;
// A matrícula é um valor inteiro. Este campo garante o compromisso de tornar públicos os dados
// e a identificação de indivíduos para qualquer situação de auditoria posterior;
// O salário é um valor real (pode ser fracionário);
// O número de funcionários é desconhecido, portanto, quando for lida
// uma tripla s com o campo função = “F” está sendo indicado o fim da sequência S.
// Seu programa deve processar a sequência S e imprimir como saída as palavras
// "Administrativo:" e "Não Administrativo:" e a seguir, para cada grupo, linhas com:
// O valor mediano (mediana) dos salários dos funcionários em funções Não administrativas;
// O valor mediano (mediana) dos salários dos funcionários em funções Administrativas.
// Dicas
// Lembre-se que:
// Quando o número de dados é par, a mediana é os dois valores centrais do grupo.
// Quando o número de dados é impar, a mediana é um único valor: o do meio.
// Exemplos de Entrada e Saída
// Entrada
// N 2017011 40000.11
// N 2017001 30000.00
// N 2017021 21000.00
// A 2013011 6400.00
// A 2016011 4010.01
// A 2013011 3000.00
// A 2011011 2000.00
// A 2017021 1010.0
// A 2017022 1300.0
// F
// Saída
// Administrativo:
// 2000.00
// 3000.00
// N Administrativo:
// 30000.00

#include <stdio.h>
#define MAX 10000

void selsort(double vetor[], int N){

	int i, j;

	for(i = 0; i < N - 1; i++){

		int imenor = i;

		for(j = i + 1; j < N; j++) if(vetor[imenor] > vetor[j]) imenor = j;

		double aux = vetor[i];
		vetor[i] = vetor[imenor];
		vetor[imenor] = aux;

	}

}

int main(void){

	char funcao;
	int contA = 0, contN = 0;
	double salariosA[MAX], salariosN[MAX];

	scanf(" %c", &funcao);

	while(funcao != 'F'){

		int matricula; scanf("%d", &matricula);

		if(funcao == 'A'){

			scanf("%lf", &salariosA[contA]);
			contA++;

		}else{

			scanf("%lf", &salariosN[contN]);
			contN++;

		}

		scanf(" %c", &funcao);

	}

	selsort(salariosA, contA); selsort(salariosN, contN);

	printf("Administrativo:\n");

	if(contA % 2 == 0){

		printf("%.2lf\n", salariosA[contA/2 - 1]);
		printf("%.2lf\n", salariosA[contA/2]);

	}else printf("%.2lf\n", salariosA[(contA - 1)/2]);

	printf("N Administrativo:\n");

	if(contN % 2 == 0){

		printf("%.2lf\n", salariosN[contN/2 - 1]);
		printf("%.2lf\n", salariosN[contN/2]);

	}else printf("%.2lf\n", salariosN[(contN - 1)/2]);

	return 0;

}