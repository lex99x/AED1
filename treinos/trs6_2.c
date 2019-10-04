// Enunciado
// ORDENANDO AS NOTAS DO ENEM
// Alunos de uma certa região do país realizaram o ENEM, e suas notas foram colocadas em uma sequência S
// de inteiros. Parte das notas já foram ordenadas de forma crescente e estão contidas na subsequência S1.
// O restante das notas, ainda em desordem, está na subsequência S2.
// Escreva um programa que:
// Insira as notas de S2, na subsequência S1, mantendo S1 ordenada após cada inserção,
// (segundo o conceito de Estabilidade da Ordenação)1.
// Como saída, imprima em ordem crescente, todas as notas obtidas pelos alunos.
// Na entrada,
// os dois últimos dígitos da nota são suas casas decimais.
// os dois primeiros valores indicam:
// i) o número total de elementos |S1| + |S2|,
// e ii) o número de elementos de S2.
// No final o programa deve imprimir o número de comparações e o número de movimentações.
// Use os textos “comparou: “ e “movimentou: “ antes dos valores correspondentes.
// Para melhor compreensão, veja o exemplo fornecido para esta questão.
// 1 Segundo este conceito a ordem dos valores iguais no vetor ordenado,
// é definido pela ordem com que aparecem no vetor já ordenado.
// Dicas
// Adapte o algoritmo de insertion sort para usar busca binária em
// S1 ao procurar a posição de inserção de cada nota de S2.
// Exemplos de Entrada e Saída
// Entrada
// 6 5
// 97054
// 97053 83296 12453 7871 3240
// Saída
// 32.40 78.71 124.53 832.96 970.53 970.54
// comparou: 8
// movimentou: 15

#include <stdio.h>

void insertionSortBinario(int vetor[], int N, int num, int* comp, int* mov){

	// Busca binária para encontrar a posição de num no vetor -->

	int inicio = 0, fim = N - 1;

	while(inicio <= fim){

		int meio = (inicio + fim)/2;

		if(num < vetor[meio]) fim = meio - 1;
		else inicio = meio + 1;

		(*comp)++;

	}

	// Arredamento para inserir num no meio do vetor -->

	int j = N - 1;

	while(j >= inicio){

		vetor[j + 1] = vetor[j];

		(*mov)++; j--;

	}

	vetor[inicio] = num; // Insere num na posição correta

}

int main(void){

	int quantTotal, quantS2;

	scanf("%d %d", &quantTotal, &quantS2);

	int quantS1 = quantTotal - quantS2, S[quantTotal], cont, comp = 0, mov = 0;

	for(cont = 0; cont < quantS1; cont++) scanf("%d", &S[cont]);

	for(cont = quantS1; cont < quantTotal; cont++){

		int nota; scanf("%d", &nota);

		insertionSortBinario(S, cont, nota, &comp, &mov);

	}

	for(cont = 0; cont < quantTotal; cont++) printf("%.2lf ", S[cont]/100.0);

	printf("\ncomparou: %d\n", comp);
	printf("movimentou: %d\n", mov);

	return 0;

}